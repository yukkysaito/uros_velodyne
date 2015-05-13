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
 * @file    urosMsgTypes.c
 * @author  Yukihiro Saito<yukky@ubi.cs.ritsumei.ac.jp>
 *
 * @brief   TCPROS message and service descriptor functions.
 */

/*===========================================================================*/
/* HEADER FILES                                                              */
/*===========================================================================*/

#include "urosMsgTypes.h"

/*===========================================================================*/
/* MESSAGE CONSTANTS                                                         */
/*===========================================================================*/

/** @addtogroup tcpros_msg_consts */
/** @{ */

/* There are no message constants.*/

/** @} */

/*===========================================================================*/
/* SERVICE CONSTANTS                                                         */
/*===========================================================================*/

/** @addtogroup tcpros_srv_consts */
/** @{ */

/* There are no service constants.*/

/** @} */

/*===========================================================================*/
/* MESSAGE FUNCTIONS                                                         */
/*===========================================================================*/

/** @addtogroup tcpros_msg_funcs */
/** @{ */

/*~~~ MESSAGE: velodyne_msgs/VelodynePacket ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>velodyne_msgs/VelodynePacket</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>velodyne_msgs/VelodynePacket</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__velodyne_msgs__VelodynePacket</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__velodyne_msgs__VelodynePacket(
  struct msg__velodyne_msgs__VelodynePacket *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(uros_time_t);
  length += (size_t)1206 * sizeof(uint8_t);

  (void)objp;
  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>velodyne_msgs/VelodynePacket</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__velodyne_msgs__VelodynePacket</code> object.
 * @return
 *          Error code.
 */
void init_msg__velodyne_msgs__VelodynePacket(
  struct msg__velodyne_msgs__VelodynePacket *objp
) {
  urosAssert(objp != NULL);

  /* Nothing to initialize.*/
  (void)objp;
}

/**
 * @brief   Cleans a TCPROS <tt>velodyne_msgs/VelodynePacket</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__velodyne_msgs__VelodynePacket</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__velodyne_msgs__VelodynePacket(
  struct msg__velodyne_msgs__VelodynePacket *objp
) {
  /* Nothing to clean.*/
  (void)objp;
}

/**
 * @brief   Receives a TCPROS <tt>velodyne_msgs/VelodynePacket</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__velodyne_msgs__VelodynePacket</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__velodyne_msgs__VelodynePacket(
  UrosTcpRosStatus *tcpstp,
  struct msg__velodyne_msgs__VelodynePacket *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->stamp); _CHKOK
  urosTcpRosRecv(tcpstp, objp->data,
                 (size_t)1206 * sizeof(uint8_t)); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__velodyne_msgs__VelodynePacket(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>velodyne_msgs/VelodynePacket</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__velodyne_msgs__VelodynePacket</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__velodyne_msgs__VelodynePacket(
  UrosTcpRosStatus *tcpstp,
  struct msg__velodyne_msgs__VelodynePacket *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->stamp); _CHKOK
  urosTcpRosSend(tcpstp, objp->data,
                 (size_t)1206 * sizeof(uint8_t)); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: std_msgs/Header ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>std_msgs/Header</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>std_msgs/Header</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__Header</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__std_msgs__Header(
  struct msg__std_msgs__Header *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(uint32_t);
  length += sizeof(uros_time_t);
  length += sizeof(uint32_t) + objp->frame_id.length;

  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>std_msgs/Header</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__std_msgs__Header</code> object.
 * @return
 *          Error code.
 */
void init_msg__std_msgs__Header(
  struct msg__std_msgs__Header *objp
) {
  urosAssert(objp != NULL);

  urosStringObjectInit(&objp->frame_id);
}

/**
 * @brief   Cleans a TCPROS <tt>std_msgs/Header</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__Header</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__std_msgs__Header(
  struct msg__std_msgs__Header *objp
) {
  if (objp == NULL) { return; }

  urosStringClean(&objp->frame_id);
}

/**
 * @brief   Receives a TCPROS <tt>std_msgs/Header</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__Header</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__std_msgs__Header(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__Header *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->seq); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->stamp); _CHKOK
  urosTcpRosRecvString(tcpstp, &objp->frame_id); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__std_msgs__Header(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>std_msgs/Header</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__Header</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__std_msgs__Header(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__Header *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->seq); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->stamp); _CHKOK
  urosTcpRosSendString(tcpstp, &objp->frame_id); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: velodyne_msgs/VelodyneScan ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>velodyne_msgs/VelodyneScan</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>velodyne_msgs/VelodyneScan</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__velodyne_msgs__VelodyneScan</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__velodyne_msgs__VelodyneScan(
  struct msg__velodyne_msgs__VelodyneScan *objp
) {
  size_t length = 0;
  uint32_t i;

  urosAssert(objp != NULL);

  length += length_msg__std_msgs__Header(&objp->header);
  length += sizeof(uint32_t);
  for (i = 0; i < objp->packets.length; ++i) {
    length += length_msg__velodyne_msgs__VelodynePacket(&objp->packets.entriesp[i]);
  }

  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>velodyne_msgs/VelodyneScan</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__velodyne_msgs__VelodyneScan</code> object.
 * @return
 *          Error code.
 */
void init_msg__velodyne_msgs__VelodyneScan(
  struct msg__velodyne_msgs__VelodyneScan *objp
) {
  uint32_t i;

  urosAssert(objp != NULL);

  init_msg__std_msgs__Header(&objp->header);
  urosTcpRosArrayObjectInit((UrosTcpRosArray *)&objp->packets);
  for (i = 0; i < objp->packets.length; ++i) {
    init_msg__velodyne_msgs__VelodynePacket(&objp->packets.entriesp[i]);
  }
}

/**
 * @brief   Cleans a TCPROS <tt>velodyne_msgs/VelodyneScan</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__velodyne_msgs__VelodyneScan</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__velodyne_msgs__VelodyneScan(
  struct msg__velodyne_msgs__VelodyneScan *objp
) {
  uint32_t i;

  if (objp == NULL) { return; }

  clean_msg__std_msgs__Header(&objp->header);
  for (i = 0; i < objp->packets.length; ++i) {
    clean_msg__velodyne_msgs__VelodynePacket(&objp->packets.entriesp[i]);
  }
  urosTcpRosArrayClean((UrosTcpRosArray *)&objp->packets);
}

/**
 * @brief   Receives a TCPROS <tt>velodyne_msgs/VelodyneScan</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__velodyne_msgs__VelodyneScan</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__velodyne_msgs__VelodyneScan(
  UrosTcpRosStatus *tcpstp,
  struct msg__velodyne_msgs__VelodyneScan *objp
) {
  uint32_t i;

  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  recv_msg__std_msgs__Header(tcpstp, &objp->header); _CHKOK
  urosTcpRosArrayObjectInit((UrosTcpRosArray *)&objp->packets);
  urosTcpRosRecvRaw(tcpstp, objp->packets.length); _CHKOK
  objp->packets.entriesp = urosArrayNew(NULL, objp->packets.length,
                                        struct msg__velodyne_msgs__VelodynePacket);
  if (objp->packets.entriesp == NULL) { tcpstp->err = UROS_ERR_NOMEM; goto _error; }
  for (i = 0; i < objp->packets.length; ++i) {
    recv_msg__velodyne_msgs__VelodynePacket(tcpstp, &objp->packets.entriesp[i]); _CHKOK
  }

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__velodyne_msgs__VelodyneScan(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>velodyne_msgs/VelodyneScan</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__velodyne_msgs__VelodyneScan</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__velodyne_msgs__VelodyneScan(
  UrosTcpRosStatus *tcpstp,
  struct msg__velodyne_msgs__VelodyneScan *objp
) {
  uint32_t i;

  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  send_msg__std_msgs__Header(tcpstp, &objp->header); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->packets.length); _CHKOK
  for (i = 0; i < objp->packets.length; ++i) {
    send_msg__velodyne_msgs__VelodynePacket(tcpstp, &objp->packets.entriesp[i]); _CHKOK
  }

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: rosgraph_msgs/Log ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>rosgraph_msgs/Log</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>rosgraph_msgs/Log</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__rosgraph_msgs__Log</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__rosgraph_msgs__Log(
  struct msg__rosgraph_msgs__Log *objp
) {
  size_t length = 0;
  uint32_t i;

  urosAssert(objp != NULL);

  length += length_msg__std_msgs__Header(&objp->header);
  length += sizeof(uint8_t);
  length += sizeof(uint32_t) + objp->name.length;
  length += sizeof(uint32_t) + objp->msg.length;
  length += sizeof(uint32_t) + objp->file.length;
  length += sizeof(uint32_t) + objp->function.length;
  length += sizeof(uint32_t);
  length += sizeof(uint32_t);
  length += (size_t)objp->topics.length * sizeof(uint32_t);
  for (i = 0; i < objp->topics.length; ++i) {
    length += objp->topics.entriesp[i].length;
  }

  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>rosgraph_msgs/Log</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__rosgraph_msgs__Log</code> object.
 * @return
 *          Error code.
 */
void init_msg__rosgraph_msgs__Log(
  struct msg__rosgraph_msgs__Log *objp
) {
  uint32_t i;

  urosAssert(objp != NULL);

  init_msg__std_msgs__Header(&objp->header);
  urosStringObjectInit(&objp->name);
  urosStringObjectInit(&objp->msg);
  urosStringObjectInit(&objp->file);
  urosStringObjectInit(&objp->function);
  urosTcpRosArrayObjectInit((UrosTcpRosArray *)&objp->topics);
  for (i = 0; i < objp->topics.length; ++i) {
    urosStringObjectInit(&objp->topics.entriesp[i]);
  }
}

/**
 * @brief   Cleans a TCPROS <tt>rosgraph_msgs/Log</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__rosgraph_msgs__Log</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__rosgraph_msgs__Log(
  struct msg__rosgraph_msgs__Log *objp
) {
  uint32_t i;

  if (objp == NULL) { return; }

  clean_msg__std_msgs__Header(&objp->header);
  urosStringClean(&objp->name);
  urosStringClean(&objp->msg);
  urosStringClean(&objp->file);
  urosStringClean(&objp->function);
  for (i = 0; i < objp->topics.length; ++i) {
    urosStringClean(&objp->topics.entriesp[i]);
  }
  urosTcpRosArrayClean((UrosTcpRosArray *)&objp->topics);
}

/**
 * @brief   Receives a TCPROS <tt>rosgraph_msgs/Log</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__rosgraph_msgs__Log</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__rosgraph_msgs__Log(
  UrosTcpRosStatus *tcpstp,
  struct msg__rosgraph_msgs__Log *objp
) {
  uint32_t i;

  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  recv_msg__std_msgs__Header(tcpstp, &objp->header); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->level); _CHKOK
  urosTcpRosRecvString(tcpstp, &objp->name); _CHKOK
  urosTcpRosRecvString(tcpstp, &objp->msg); _CHKOK
  urosTcpRosRecvString(tcpstp, &objp->file); _CHKOK
  urosTcpRosRecvString(tcpstp, &objp->function); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->line); _CHKOK
  urosTcpRosArrayObjectInit((UrosTcpRosArray *)&objp->topics);
  urosTcpRosRecvRaw(tcpstp, objp->topics.length); _CHKOK
  objp->topics.entriesp = urosArrayNew(NULL, objp->topics.length,
                                       UrosString);
  if (objp->topics.entriesp == NULL) { tcpstp->err = UROS_ERR_NOMEM; goto _error; }
  for (i = 0; i < objp->topics.length; ++i) {
    urosTcpRosRecvString(tcpstp, &objp->topics.entriesp[i]); _CHKOK
  }

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__rosgraph_msgs__Log(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>rosgraph_msgs/Log</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__rosgraph_msgs__Log</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__rosgraph_msgs__Log(
  UrosTcpRosStatus *tcpstp,
  struct msg__rosgraph_msgs__Log *objp
) {
  uint32_t i;

  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  send_msg__std_msgs__Header(tcpstp, &objp->header); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->level); _CHKOK
  urosTcpRosSendString(tcpstp, &objp->name); _CHKOK
  urosTcpRosSendString(tcpstp, &objp->msg); _CHKOK
  urosTcpRosSendString(tcpstp, &objp->file); _CHKOK
  urosTcpRosSendString(tcpstp, &objp->function); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->line); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->topics.length); _CHKOK
  for (i = 0; i < objp->topics.length; ++i) {
    urosTcpRosSendString(tcpstp, &objp->topics.entriesp[i]); _CHKOK
  }

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/** @} */

/*===========================================================================*/
/* SERVICE FUNCTIONS                                                         */
/*===========================================================================*/

/** @addtogroup tcpros_srv_funcs */
/** @{ */

/* There are no service types.*/

/** @} */

/*===========================================================================*/
/* GLOBAL FUNCTIONS                                                          */
/*===========================================================================*/

/** @addtogroup tcpros_funcs */
/** @{ */

/**
 * @brief   Static TCPROS types registration.
 * @details Statically registers all the TCPROS message and service types used
 *          within this source file.
 * @note    Should be called by @p urosUserRegisterStaticMsgTypes().
 * @see     urosUserRegisterStaticMsgTypes()
 */
void urosMsgTypesRegStaticTypes(void) {

  /* MESSAGE TYPES */

  /* rosgraph_msgs/Log */
  urosRegisterStaticMsgTypeSZ("rosgraph_msgs/Log",
                              NULL, "acffd30cd6b6de30f120938c17c593fb");

  /* std_msgs/Header */
  urosRegisterStaticMsgTypeSZ("std_msgs/Header",
                              NULL, "2176decaecbce78abc3b96ef049fabed");

  /* velodyne_msgs/VelodynePacket */
  urosRegisterStaticMsgTypeSZ("velodyne_msgs/VelodynePacket",
                              NULL, "ae4f90a23256f44e82baa08dd45c3456");

  /* velodyne_msgs/VelodyneScan */
  urosRegisterStaticMsgTypeSZ("velodyne_msgs/VelodyneScan",
                              NULL, "50804fc9533a0e579e6322c04ae70566");
}

/** @} */

