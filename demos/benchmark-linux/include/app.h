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

/**
 * @file    app.c
 * @author  Andrea Zoppi <texzk@email.it>
 *
 * @brief   Application source header.
 */

#ifndef _APP_H_
#define _APP_H_

/*===========================================================================*/
/* HEADER FILES                                                              */
/*===========================================================================*/

#include <urosBase.h>

/*===========================================================================*/
/* TYPES & MACROS                                                            */
/*===========================================================================*/

/**
 * @brief   Stream counters.
 */
typedef struct streamcnt_t {
  unsigned long numMsgs;        /**< @brief Total number of exchanged messages.*/
  size_t        numBytes;       /**< @brief Total exchanged size.*/
  unsigned long deltaMsgs;      /**< @brief Incremental number of exchanged messages.*/
  size_t        deltaBytes;     /**< @brief Incremental exchanged size.*/
} streamcnt_t;

/**
 * @brief   CPU usage time counters (jiffies).
 */
typedef struct cpucnt_t {
  unsigned long user;           /**< @brief User-level CPU time.*/
  unsigned long nice;           /**< @brief Niced user-level CPU time.*/
  unsigned long system;         /**< @brief System-level CPU time.*/
  unsigned long idle;           /**< @brief Idle CPU time.*/
  unsigned long iowait;         /**< @brief I/O wait time.*/
  unsigned long irq;            /**< @brief Interrupt service time.*/
  unsigned long softirq;        /**< @brief Software interrupt service time.*/
  unsigned long misc;           /**< @brief Remaining counters, aggregated.*/
} cpucnt_t;

/**
 * @brief   Benchmark status.
 */
typedef struct benchmark_t {
  UrosMutex     lock;           /**< @brief Lock word.*/

  /* Configuration.*/
  uint32_t      rate;           /**< @brief Packets/s.*/
  UrosString    payload;        /**< @brief Packet payload string.*/
  uros_bool_t   hasOutPub;      /**< @brief Creates the publisher of
                                 *          <tt>/benchmark/output</tt>.*/
  uros_bool_t   hasInSub;       /**< @brief Creates the subscriber of
                                 *          <tt>/benchmark/input</tt>.*/
  uros_bool_t   hasOutSub;      /**< @brief Creates the subscriber of
                                 *          <tt>/benchmark/output</tt>.*/

  /* Meters.*/
  cpucnt_t      curCpu;         /**< @brief Current CPU usages.*/
  cpucnt_t      oldCpu;         /**< @brief Previous CPU usages.*/
  streamcnt_t   inCount;        /**< @brief Incoming stream counters.*/
  streamcnt_t   outCount;       /**< @brief Outgoing stream counters.*/
  UrosThreadId  printerId;      /**< @brief Stats printer thread.*/
} benchmark_t;

/** @brief Stack size of the printer thread.*/
#define PRINTER_STKLEN      (PTHREAD_STACK_MIN << 1)

/** @brief Skips incoming data in handlers.*/
#define HANDLERS_INPUT_SKIP 1

/** @brief Tells whether @p pthread_getname_np() adds a trailing newline.*/
#define PTHREAD_GETNAME_NP_NEWLINE  0

/*===========================================================================*/
/* GLOBAL VARIABLES                                                          */
/*===========================================================================*/

extern benchmark_t benchmark;
extern const UrosString rateparamname, sizeparamname;

/*===========================================================================*/
/* GLOBAL PROTOTYPES                                                         */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

uros_err_t app_printer_thread(void* argp);
void app_printusage(void);
uros_bool_t app_parseargs(int argc, char *argv[]);
void app_initialize(void);
void app_wait_exit(void);

#ifdef __cplusplus
}
#endif

#endif /* _APP_H_ */
