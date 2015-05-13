/*
Copyright (c) 2012-2013, Politecnico di Milano. All rights reserved.

Andrea Zoppi <texzk@email.it>
Martino Migliavacca <martino.migliavacca@gmail.com>

http://airlab.elet.polimi.it/
http://www.openrobots.com/

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*===========================================================================*/
/* HEADER FILES                                                              */
/*===========================================================================*/

#include <stdio.h>

#include <urosNode.h>

/* #include "app.h" */
#include "urosHandlers.h"
#include <urosBase.h>
#include <urosUser.h>
#include <math.h>
typedef struct queue_t {
  UrosSem       freeSem;
  UrosSem       usedSem;
  unsigned      length;
  unsigned      head;
  unsigned      tail;
  UrosMutex     slotsMtx;
  void          **slots;
} fifo_t;

fifo_t rosoutQueue;

/*===========================================================================*/
/* GLOBAL FUNCTIONS                                                          */
/*===========================================================================*/
/*~~~ FIFO MESSAGE QUEUE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void fifo_init(fifo_t *queuep, unsigned length) {

  urosAssert(queuep != NULL);
  urosAssert(length > 0);

  urosSemObjectInit(&queuep->freeSem, length);
  urosSemObjectInit(&queuep->usedSem, 0);
  queuep->length = length;
  queuep->head = 0;
  queuep->tail = 0;
  urosMutexObjectInit(&queuep->slotsMtx);
  queuep->slots = urosArrayNew(NULL, length, void *);
  urosAssert(queuep->slots != NULL);
}

void fifo_enqueue(fifo_t *queuep, void *msgp) {

  urosAssert(queuep != NULL);
  urosAssert(msgp != NULL);

  urosSemWait(&queuep->freeSem);
  urosMutexLock(&queuep->slotsMtx);
  queuep->slots[queuep->tail] = msgp;
  if (++queuep->tail >= queuep->length) {
    queuep->tail = 0;
  }
  urosMutexUnlock(&queuep->slotsMtx);
  urosSemSignal(&queuep->usedSem);
}

void *fifo_dequeue(fifo_t *queuep) {

  void *msgp;

  urosAssert(queuep != NULL);

  urosSemWait(&queuep->usedSem);
  urosMutexLock(&queuep->slotsMtx);
  msgp = queuep->slots[queuep->head];
  if (++queuep->head >= queuep->length) {
    queuep->head = 0;
  }
  urosMutexUnlock(&queuep->slotsMtx);
  urosSemSignal(&queuep->freeSem);
  return msgp;
}
/*~~~ ROSOUT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void rosout_post(UrosString *strp, uros_bool_t costant, uint8_t level,
                 const char *fileszp, int line, const char *funcp) {

  static uint32_t seq = 0;

  struct msg__rosgraph_msgs__Log *msgp;

  urosAssert(urosStringIsValid(strp));

  msgp = urosNew(NULL, struct msg__rosgraph_msgs__Log);
  urosAssert(msgp != NULL);
  init_msg__rosgraph_msgs__Log(msgp);

  msgp->header.frame_id = urosStringAssignZ(costant ? "1" : "0");
  msgp->header.seq = seq++;
  msgp->header.stamp.sec = urosGetTimestampMsec();
  msgp->header.stamp.nsec = (msgp->header.stamp.sec % 1000) * 1000000;
  msgp->header.stamp.sec /= 1000;
  msgp->level = level;
  msgp->name = urosNode.config.nodeName;
  msgp->msg = *strp;
  msgp->file = urosStringAssignZ(fileszp);
  msgp->function = urosStringAssignZ(funcp);
  msgp->line = line;

  fifo_enqueue(&rosoutQueue, (void *)msgp);
}

void rosout_fetch(struct msg__rosgraph_msgs__Log **msgpp) {

  urosAssert(msgpp != NULL);

  *msgpp = (struct msg__rosgraph_msgs__Log *)fifo_dequeue(&rosoutQueue);
}


int main (int argc, char *argv[]) {

  (void)argc;
  (void)argv;

  printf("=> uROS Node Test <=\n");

  /* Initialize the application.*/
  /* app_initialize(); */


  /* Initialize the uROS system.*/
  urosInit();
  fifo_init(&rosoutQueue, 8);
  urosNodeCreateThread();

  /* Wait until the node has shut down.*/
  urosThreadJoin(urosNode.status.nodeThreadId);

  printf("\n(Node has shut down successfully)\n");
  return 0;
}
