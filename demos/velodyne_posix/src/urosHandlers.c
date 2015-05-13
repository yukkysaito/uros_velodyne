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
 * @file    urosHandlers.c
 * @author  Yukihiro Saito<yukky@ubi.cs.ritsumei.ac.jp>
 *
 * @brief   TCPROS topic and service handlers.
 */

/*===========================================================================*/
/* HEADER FILES                                                              */
/*===========================================================================*/

#include "urosHandlers.h"

#include <urosNode.h>
#include <urosTcpRos.h>
#include <urosUser.h>

/*===========================================================================*/
/* PUBLISHED TOPIC FUNCTIONS                                                 */
/*===========================================================================*/

/** @addtogroup tcpros_pubtopic_funcs */
/** @{ */

/*~~~ PUBLISHED TOPIC: /rosout ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/rosout</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/rosout</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__rosout(UrosTcpRosStatus *tcpstp) {

    /* Message allocation and initialization.*/
    UROS_TPC_INIT_H(msg__rosgraph_msgs__Log);

    /* Published messages loop.*/
    while (!urosTcpRosStatusCheckExit(tcpstp)) {
        /* TODO: Generate the contents of the message.*/
        urosThreadSleepSec(1); continue; /* TODO: Remove this dummy line.*/

        /* Send the message.*/
        UROS_MSG_SEND_LENGTH(msgp, msg__rosgraph_msgs__Log);
        UROS_MSG_SEND_BODY(msgp, msg__rosgraph_msgs__Log);

        /* Dispose the contents of the message.*/
        clean_msg__rosgraph_msgs__Log(msgp);
    }
    tcpstp->err = UROS_OK;

_finally:
    /* Message deinitialization and deallocation.*/
    UROS_TPC_UNINIT_H(msg__rosgraph_msgs__Log);
    return tcpstp->err;
}

/** @} */

/*~~~ PUBLISHED TOPIC: /vlp_16 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/vlp_16</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/vlp_16</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__vlp_16(UrosTcpRosStatus *tcpstp) {

    /* Message allocation and initialization.*/
    UROS_TPC_INIT_H(msg__velodyne_msgs__VelodyneScan);

    /* Published messages loop.*/
    while (!urosTcpRosStatusCheckExit(tcpstp)) {
        /* TODO: Generate the contents of the message.*/
        printf("velodyne_driver published\n");

        double packet_rate;
        char *model_full_name = "VLP-16";


        urosThreadSleepSec(1); continue; /* TODO: Remove this dummy line.*/

        /* Send the message.*/
        UROS_MSG_SEND_LENGTH(msgp, msg__velodyne_msgs__VelodyneScan);
        UROS_MSG_SEND_BODY(msgp, msg__velodyne_msgs__VelodyneScan);

        /* Dispose the contents of the message.*/
        clean_msg__velodyne_msgs__VelodyneScan(msgp);
    }
    tcpstp->err = UROS_OK;

_finally:
    /* Message deinitialization and deallocation.*/
    UROS_TPC_UNINIT_H(msg__velodyne_msgs__VelodyneScan);
    return tcpstp->err;
}

/** @} */

/** @} */

/*===========================================================================*/
/* SUBSCRIBED TOPIC FUNCTIONS                                                */
/*===========================================================================*/

/** @addtogroup tcpros_subtopic_funcs */
/** @{ */

/* There are no subscribed topics.*/

/** @} */

/*===========================================================================*/
/* PUBLISHED SERVICE FUNCTIONS                                               */
/*===========================================================================*/

/** @addtogroup tcpros_pubservice_funcs */
/** @{ */

/* There are no published services.*/

/** @} */

/*===========================================================================*/
/* CALLED SERVICE FUNCTIONS                                                  */
/*===========================================================================*/

/** @addtogroup tcpros_callservice_funcs */
/** @{ */

/* There are no called services.*/

/** @} */

/*===========================================================================*/
/* GLOBAL FUNCTIONS                                                          */
/*===========================================================================*/

/** @addtogroup tcpros_funcs */
/** @{ */

/**
 * @brief   Registers all the published topics to the Master node.
 * @note    Should be called at node initialization.
 */
void urosHandlersPublishTopics(void) {

    /* /rosout */
    urosNodePublishTopicSZ(
        "/rosout",
        "rosgraph_msgs/Log",
        (uros_proc_f)pub_tpc__rosout,
        uros_nulltopicflags
        );

    /* /vlp_16 */
    urosNodePublishTopicSZ(
        "/vlp_16",
        "velodyne_msgs/VelodyneScan",
        (uros_proc_f)pub_tpc__vlp_16,
        uros_nulltopicflags
        );
}

/**
 * @brief   Unregisters all the published topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnpublishTopics(void) {

    /* /rosout */
    urosNodeUnpublishTopicSZ(
        "/rosout"
        );

    /* /vlp_16 */
    urosNodeUnpublishTopicSZ(
        "/vlp_16"
        );
}

/**
 * @brief   Registers all the subscribed topics to the Master node.
 * @note    Should be called at node initialization.
 */
void urosHandlersSubscribeTopics(void) {

    /* No topics to subscribe to.*/
}

/**
 * @brief   Unregisters all the subscribed topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnsubscribeTopics(void) {

    /* No topics to unsubscribe from.*/
}

/**
 * @brief   Registers all the published services to the Master node.
 * @note    Should be called at node initialization.
 */
void urosHandlersPublishServices(void) {

    /* No services to publish.*/
}

/**
 * @brief   Unregisters all the published services to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnpublishServices(void) {

    /* No services to unpublish.*/
}

/** @} */
