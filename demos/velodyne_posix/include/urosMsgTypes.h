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
 * @file    urosMsgTypes.h
 * @author  Yukihiro Saito<yukky@ubi.cs.ritsumei.ac.jp>
 *
 * @brief   TCPROS message and service descriptors.
 */

#ifndef _UROSMSGTYPES_H_
#define _UROSMSGTYPES_H_

/*===========================================================================*/
/* HEADER FILES                                                              */
/*===========================================================================*/

#include <urosTcpRos.h>

#ifdef __cplusplus
extern "C" {
#endif

/*===========================================================================*/
/*  MESSAGE TYPES                                                            */
/*===========================================================================*/

/** @addtogroup tcpros_msg_types */
/** @{ */

/*~~~ MESSAGE: velodyne_msgs/VelodynePacket ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>velodyne_msgs/VelodynePacket</tt> message descriptor.
 * @details MD5 sum: <tt>ae4f90a23256f44e82baa08dd45c3456</tt>.
 */
struct msg__velodyne_msgs__VelodynePacket {

  /** @brief TODO: @p stamp description.*/
  uros_time_t   stamp;

  /** @brief TODO: @p data description.*/
  uint8_t       data[1206];
};

/*~~~ MESSAGE: std_msgs/Header ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>std_msgs/Header</tt> message descriptor.
 * @details MD5 sum: <tt>2176decaecbce78abc3b96ef049fabed</tt>.
 */
struct msg__std_msgs__Header {

  /** @brief TODO: @p seq description.*/
  uint32_t      seq;

  /** @brief TODO: @p stamp description.*/
  uros_time_t   stamp;

  /** @brief TODO: @p frame_id description.*/
  UrosString    frame_id;
};

/*~~~ MESSAGE: velodyne_msgs/VelodyneScan ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>velodyne_msgs/VelodyneScan</tt> message descriptor.
 * @details MD5 sum: <tt>50804fc9533a0e579e6322c04ae70566</tt>.
 */
struct msg__velodyne_msgs__VelodyneScan {

  /** @brief TODO: @p header description.*/
  struct msg__std_msgs__Header                              header;

  /** @brief TODO: @p packets description.*/
  UROS_VARARR(struct msg__velodyne_msgs__VelodynePacket)    packets;
};

/*~~~ MESSAGE: rosgraph_msgs/Log ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>rosgraph_msgs/Log</tt> message descriptor.
 * @details MD5 sum: <tt>acffd30cd6b6de30f120938c17c593fb</tt>.
 */
struct msg__rosgraph_msgs__Log {

  /** @brief TODO: @p header description.*/
  struct msg__std_msgs__Header  header;

  /** @brief TODO: @p level description.*/
  uint8_t                       level;

  /** @brief TODO: @p name description.*/
  UrosString                    name;

  /** @brief TODO: @p msg description.*/
  UrosString                    msg;

  /** @brief TODO: @p file description.*/
  UrosString                    file;

  /** @brief TODO: @p function description.*/
  UrosString                    function;

  /** @brief TODO: @p line description.*/
  uint32_t                      line;

  /** @brief TODO: @p topics description.*/
  UROS_VARARR(UrosString)       topics;
};

/** @} */

/*===========================================================================*/
/* SERVICE TYPES                                                             */
/*===========================================================================*/

/** @addtogroup tcpros_srv_types */
/** @{ */

/* There are no service types.*/

/** @} */

/*===========================================================================*/
/* MESSAGE CONSTANTS                                                         */
/*===========================================================================*/

/** @addtogroup tcpros_msg_consts */
/** @{ */

/*~~~ MESSAGE: rosgraph_msgs/Log ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>rosgraph_msgs/Log</tt> */
/** @{ */

/** @brief TODO: <tt>rosgraph_msgs/Log.DEBUG</tt> description.*/
#define msg__rosgraph_msgs__Log__DEBUG      ((uint8_t)1)

/** @brief TODO: <tt>rosgraph_msgs/Log.INFO</tt> description.*/
#define msg__rosgraph_msgs__Log__INFO       ((uint8_t)2)

/** @brief TODO: <tt>rosgraph_msgs/Log.WARN</tt> description.*/
#define msg__rosgraph_msgs__Log__WARN       ((uint8_t)4)

/** @brief TODO: <tt>rosgraph_msgs/Log.ERROR</tt> description.*/
#define msg__rosgraph_msgs__Log__ERROR      ((uint8_t)8)

/** @brief TODO: <tt>rosgraph_msgs/Log.FATAL</tt> description.*/
#define msg__rosgraph_msgs__Log__FATAL      ((uint8_t)16)

/** @} */

/** @} */

/*===========================================================================*/
/* SERVICE CONSTANTS                                                         */
/*===========================================================================*/

/** @addtogroup tcpros_srv_consts */
/** @{ */

/* There are no service costants.*/

/** @} */

/*===========================================================================*/
/* MESSAGE PROTOTYPES                                                        */
/*===========================================================================*/

/*~~~ MESSAGE: velodyne_msgs/VelodynePacket ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__velodyne_msgs__VelodynePacket(
  struct msg__velodyne_msgs__VelodynePacket *objp
);
void init_msg__velodyne_msgs__VelodynePacket(
  struct msg__velodyne_msgs__VelodynePacket *objp
);
void clean_msg__velodyne_msgs__VelodynePacket(
  struct msg__velodyne_msgs__VelodynePacket *objp
);
uros_err_t recv_msg__velodyne_msgs__VelodynePacket(
  UrosTcpRosStatus *tcpstp,
  struct msg__velodyne_msgs__VelodynePacket *objp
);
uros_err_t send_msg__velodyne_msgs__VelodynePacket(
  UrosTcpRosStatus *tcpstp,
  struct msg__velodyne_msgs__VelodynePacket *objp
);

/*~~~ MESSAGE: std_msgs/Header ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__std_msgs__Header(
  struct msg__std_msgs__Header *objp
);
void init_msg__std_msgs__Header(
  struct msg__std_msgs__Header *objp
);
void clean_msg__std_msgs__Header(
  struct msg__std_msgs__Header *objp
);
uros_err_t recv_msg__std_msgs__Header(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__Header *objp
);
uros_err_t send_msg__std_msgs__Header(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__Header *objp
);

/*~~~ MESSAGE: velodyne_msgs/VelodyneScan ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__velodyne_msgs__VelodyneScan(
  struct msg__velodyne_msgs__VelodyneScan *objp
);
void init_msg__velodyne_msgs__VelodyneScan(
  struct msg__velodyne_msgs__VelodyneScan *objp
);
void clean_msg__velodyne_msgs__VelodyneScan(
  struct msg__velodyne_msgs__VelodyneScan *objp
);
uros_err_t recv_msg__velodyne_msgs__VelodyneScan(
  UrosTcpRosStatus *tcpstp,
  struct msg__velodyne_msgs__VelodyneScan *objp
);
uros_err_t send_msg__velodyne_msgs__VelodyneScan(
  UrosTcpRosStatus *tcpstp,
  struct msg__velodyne_msgs__VelodyneScan *objp
);

/*~~~ MESSAGE: rosgraph_msgs/Log ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__rosgraph_msgs__Log(
  struct msg__rosgraph_msgs__Log *objp
);
void init_msg__rosgraph_msgs__Log(
  struct msg__rosgraph_msgs__Log *objp
);
void clean_msg__rosgraph_msgs__Log(
  struct msg__rosgraph_msgs__Log *objp
);
uros_err_t recv_msg__rosgraph_msgs__Log(
  UrosTcpRosStatus *tcpstp,
  struct msg__rosgraph_msgs__Log *objp
);
uros_err_t send_msg__rosgraph_msgs__Log(
  UrosTcpRosStatus *tcpstp,
  struct msg__rosgraph_msgs__Log *objp
);

/*===========================================================================*/
/* SERVICE PROTOTYPES                                                        */
/*===========================================================================*/

/* There are no service types.*/

/*===========================================================================*/
/* GLOBAL PROTOTYPES                                                         */
/*===========================================================================*/

void urosMsgTypesRegStaticTypes(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _UROSMSGTYPES_H_ */

