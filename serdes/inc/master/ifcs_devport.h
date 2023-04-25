/*
 *-------------------------------------------------------------------------------------
 * Copyright (c) (2021) Marvell. All rights reserved.
 * The following file is subject to the limited use license agreement
 * by and between Marvell and you your employer or other entity on
 * behalf of whom you act. In the absence of such license agreement
 * the following file is subject to Marvell’s standard Limited Use License Agreement.
 *-------------------------------------------------------------------------------------
 */

 /*  */

/**
 * @file  ifcs_devport.h
 * @brief IFCS DEVPORT API's
 */


#ifndef __IFCS_DEVPORT_H__
#define __IFCS_DEVPORT_H__

#include "ifcs_types.h"
#include "ifcs_status.h"

/**
 * @brief Attribute data for port type
 */
typedef enum ifcs_devport_type_e {
    IFCS_DEVPORT_TYPE_ETH    = 0, ///< ETH
    IFCS_DEVPORT_TYPE_AUX    = 1, ///< AUX
    IFCS_DEVPORT_TYPE_CPU    = 2, ///< CPU
    IFCS_DEVPORT_TYPE_IL     = 3, ///< IL
    IFCS_DEVPORT_TYPE_RECIRC = 4, ///< RECIRC
} ifcs_devport_type_t;

/**
 * @brief port state
 */
typedef enum ifcs_devport_state_e {
    IFCS_DEVPORT_STATE_UNINITED    = 0, ///< UNINITED
    IFCS_DEVPORT_STATE_INITED      = 1, ///< INITED
    IFCS_DEVPORT_STATE_DISABLED    = 2, ///< DISABLED
    IFCS_DEVPORT_STATE_ENABLED     = 3, ///< ENABLED
    IFCS_DEVPORT_STATE_AN_COMPLETE = 4, ///< AN_COMPLETE
    IFCS_DEVPORT_STATE_LINK_UP     = 5, ///< LINK_UP
    IFCS_DEVPORT_STATE_BUSY        = 6, ///< BUSY
} ifcs_devport_state_t;

/**
 * @brief PFC mode
 */
typedef enum ifcs_devport_pfc_mode_e {
    IFCS_DEVPORT_PFC_MODE_COMBINED = 0, ///< COMBINED
    IFCS_DEVPORT_PFC_MODE_SEPARATE = 1, ///< SEPARATE
} ifcs_devport_pfc_mode_t;

/**
 * @brief Pause mode
 */
typedef enum ifcs_devport_pause_mode_e {
    IFCS_DEVPORT_PAUSE_MODE_COMBINED = 0, ///< COMBINED
    IFCS_DEVPORT_PAUSE_MODE_SEPARATE = 1, ///< SEPARATE
} ifcs_devport_pause_mode_t;

/**
 * @brief Attribute data for FEC mode
 */
typedef enum ifcs_devport_fec_mode_e {
    IFCS_DEVPORT_FEC_MODE_NONE = 0, ///< No FEC mode
    IFCS_DEVPORT_FEC_MODE_KR   = 1, ///< Enable KR FEC mode
    IFCS_DEVPORT_FEC_MODE_KP   = 2, ///< Enable KP FEC Mode
    IFCS_DEVPORT_FEC_MODE_FC   = 3, ///< Enable FC FEC mode
} ifcs_devport_fec_mode_t;

/**
 * @brief Attribute data for Loopback mode
 */
typedef enum ifcs_devport_loopback_e {
    IFCS_DEVPORT_LOOPBACK_NONE        = 0, ///< Disable Loopback
    IFCS_DEVPORT_LOOPBACK_PCS         = 1, ///< Enable PCS/MAC loopback
    IFCS_DEVPORT_LOOPBACK_PMA         = 2, ///< Enable PMA/SerDes loopback
    IFCS_DEVPORT_LOOPBACK_REMOTE_LPBK = 3, ///< Enable Retimer mode loopback
} ifcs_devport_loopback_t;

/**
 * @brief isg type
 */
typedef enum ifcs_devport_serdes_group_e {
    IFCS_DEVPORT_SERDES_GROUP_NONE  = 0,  ///< NONE
    IFCS_DEVPORT_SERDES_GROUP_ISG0  = 1,  ///< ISG0
    IFCS_DEVPORT_SERDES_GROUP_ISG1  = 2,  ///< ISG1
    IFCS_DEVPORT_SERDES_GROUP_ISG2  = 3,  ///< ISG2
    IFCS_DEVPORT_SERDES_GROUP_ISG3  = 4,  ///< ISG3
    IFCS_DEVPORT_SERDES_GROUP_ISG4  = 5,  ///< ISG4
    IFCS_DEVPORT_SERDES_GROUP_ISG5  = 6,  ///< ISG5
    IFCS_DEVPORT_SERDES_GROUP_ISG6  = 7,  ///< ISG6
    IFCS_DEVPORT_SERDES_GROUP_ISG7  = 8,  ///< ISG7
    IFCS_DEVPORT_SERDES_GROUP_ISG8  = 9,  ///< ISG8
    IFCS_DEVPORT_SERDES_GROUP_ISG9  = 10, ///< ISG9
    IFCS_DEVPORT_SERDES_GROUP_ISG10 = 11, ///< ISG10
    IFCS_DEVPORT_SERDES_GROUP_ISG11 = 12, ///< ISG11
    IFCS_DEVPORT_SERDES_GROUP_ISG12 = 13, ///< ISG12
    IFCS_DEVPORT_SERDES_GROUP_ISG13 = 14, ///< ISG13
    IFCS_DEVPORT_SERDES_GROUP_ISG14 = 15, ///< ISG14
    IFCS_DEVPORT_SERDES_GROUP_ISG15 = 16, ///< ISG15
    IFCS_DEVPORT_SERDES_GROUP_ISG16 = 17, ///< ISG16
    IFCS_DEVPORT_SERDES_GROUP_ISG17 = 18, ///< ISG17
    IFCS_DEVPORT_SERDES_GROUP_ISG18 = 19, ///< ISG18
    IFCS_DEVPORT_SERDES_GROUP_ISG19 = 20, ///< ISG19
    IFCS_DEVPORT_SERDES_GROUP_ISG20 = 21, ///< ISG20
    IFCS_DEVPORT_SERDES_GROUP_ISG21 = 22, ///< ISG21
    IFCS_DEVPORT_SERDES_GROUP_ISG22 = 23, ///< ISG22
    IFCS_DEVPORT_SERDES_GROUP_ISG23 = 24, ///< ISG23
    IFCS_DEVPORT_SERDES_GROUP_ISG24 = 25, ///< ISG24
    IFCS_DEVPORT_SERDES_GROUP_ISG25 = 26, ///< ISG25
    IFCS_DEVPORT_SERDES_GROUP_ISG26 = 27, ///< ISG26
    IFCS_DEVPORT_SERDES_GROUP_ISG27 = 28, ///< ISG27
    IFCS_DEVPORT_SERDES_GROUP_ISG28 = 29, ///< ISG28
    IFCS_DEVPORT_SERDES_GROUP_ISG29 = 30, ///< ISG29
    IFCS_DEVPORT_SERDES_GROUP_ISG30 = 31, ///< ISG30
    IFCS_DEVPORT_SERDES_GROUP_ISG31 = 32, ///< ISG31
    IFCS_DEVPORT_SERDES_GROUP_MSER0 = 33, ///< MSER0
} ifcs_devport_serdes_group_t;

/**
 * @brief PRBS polynomials
 */
typedef enum ifcs_devport_serdes_polynomial_e {
    IFCS_DEVPORT_SERDES_POLYNOMIAL_NOTCONFIGURED = 0, ///< NOTCONFIGURED
    IFCS_DEVPORT_SERDES_POLYNOMIAL_PRBS7         = 1, ///< PRBS7
    IFCS_DEVPORT_SERDES_POLYNOMIAL_PRBS9         = 2, ///< PRBS9
    IFCS_DEVPORT_SERDES_POLYNOMIAL_PRBS11        = 3, ///< PRBS11
    IFCS_DEVPORT_SERDES_POLYNOMIAL_PRBS13        = 4, ///< PRBS13
    IFCS_DEVPORT_SERDES_POLYNOMIAL_PRBS15        = 5, ///< PRBS15
    IFCS_DEVPORT_SERDES_POLYNOMIAL_PRBS23        = 6, ///< PRBS23
    IFCS_DEVPORT_SERDES_POLYNOMIAL_PRBS31        = 7, ///< PRBS31
} ifcs_devport_serdes_polynomial_t;

/**
 * @brief PRBS bit rate
 */
typedef enum ifcs_devport_serdes_prbs_rate_e {
    IFCS_DEVPORT_SERDES_PRBS_RATE_NOTCONFIGURED = 0, ///< NOTCONFIGURED
    IFCS_DEVPORT_SERDES_PRBS_RATE_10_3125GBS    = 1, ///< 10.3125Gb/s
    IFCS_DEVPORT_SERDES_PRBS_RATE_25_78125GBS   = 2, ///< 25.78125Gb/s
    IFCS_DEVPORT_SERDES_PRBS_RATE_26_5625GBS    = 3, ///< 26.5625Gb/s
    IFCS_DEVPORT_SERDES_PRBS_RATE_27_1875GBS    = 4, ///< 27_1875GBS
    IFCS_DEVPORT_SERDES_PRBS_RATE_28_125GBS     = 5, ///< 28.125Gb/s
    IFCS_DEVPORT_SERDES_PRBS_RATE_51_5625GBS    = 6, ///< 51.5625Gb/s
    IFCS_DEVPORT_SERDES_PRBS_RATE_53_125GBS     = 7, ///< 53.125Gb/s
    IFCS_DEVPORT_SERDES_PRBS_RATE_54_375GBS     = 8, ///< 54.375Gb/s
    IFCS_DEVPORT_SERDES_PRBS_RATE_56_25GBS      = 9, ///< 56.25Gb/s
} ifcs_devport_serdes_prbs_rate_t;

/**
 * @brief RX equalization fine tune
 */
typedef enum ifcs_devport_serdes_rx_eq_fine_tune_e {
    IFCS_DEVPORT_SERDES_RX_EQ_FINE_TUNE_SINGLE     = 0, ///< SINGLE
    IFCS_DEVPORT_SERDES_RX_EQ_FINE_TUNE_CONTINUOUS = 1, ///< CONTINUOUS
} ifcs_devport_serdes_rx_eq_fine_tune_t;

/**
 * @brief Signal detect modes
 */
typedef enum ifcs_devport_signal_detect_mode_e {
    IFCS_DEVPORT_SIGNAL_DETECT_MODE_MODE1 = 0, ///< MODE1
    IFCS_DEVPORT_SIGNAL_DETECT_MODE_MODE2 = 1, ///< MODE2
} ifcs_devport_signal_detect_mode_t;

/**
 * @brief Rx gainshape number
 */
typedef enum ifcs_devport_serdes_rx_gainshape_e {
    IFCS_DEVPORT_SERDES_RX_GAINSHAPE_0 = 0, ///< 0
    IFCS_DEVPORT_SERDES_RX_GAINSHAPE_1 = 1, ///< 1
    IFCS_DEVPORT_SERDES_RX_GAINSHAPE_2 = 2, ///< 2
    IFCS_DEVPORT_SERDES_RX_GAINSHAPE_3 = 3, ///< 3
} ifcs_devport_serdes_rx_gainshape_t;

/**
 * @brief PFC watchdog mitigation actions
 */
typedef enum ifcs_pfc_wd_mitigation_action_e {
    IFCS_PFC_WD_MITIGATION_ACTION_FORWARD = 0, ///< FORWARD
    IFCS_PFC_WD_MITIGATION_ACTION_DROP    = 1, ///< DROP
} ifcs_pfc_wd_mitigation_action_t;

/**
 * @brief PFC watchdog restoration mode
 */
typedef enum ifcs_pfc_wd_restoration_mode_e {
    IFCS_PFC_WD_RESTORATION_MODE_AUTO   = 0, ///< Restore if no PFC frames received for 'pfc_wd_restoration_threshold' time
    IFCS_PFC_WD_RESTORATION_MODE_FORCE  = 1, ///< Restore forcefully after 'pfc_wd_restoration_threshold' time even if PFC frames are received
    IFCS_PFC_WD_RESTORATION_MODE_MANUAL = 2, ///< Restore only when user writes IFCS_BOOL_TRUE into 'pfc_wd_manual_restoration_trigger' attribute even if PFC frames are received
} ifcs_pfc_wd_restoration_mode_t;

/**
 * @brief Tx PLL loop bandwidth
 */
typedef enum ifcs_tx_bw_freq_e {
    IFCS_TX_BW_FREQ_NOTCONFIGURED = 0x2719, ///< NOTCONFIGURED
    IFCS_TX_BW_FREQ_10_5MHZ       = 0x271E, ///< 10_5MHZ
} ifcs_tx_bw_freq_t;

/**
 * @brief PRBS modes
 */
typedef enum ifcs_devport_prbs_mode_e {
    IFCS_DEVPORT_PRBS_MODE_NOTCONFIGURED = 0, ///< NOTCONFIGURED
    IFCS_DEVPORT_PRBS_MODE_NO_DFE_TUNE   = 1, ///< NO_DFE_TUNE
} ifcs_devport_prbs_mode_t;

/**
 * @brief PRBS sync status
 */
typedef enum ifcs_devport_prbs_sync_status_e {
    IFCS_DEVPORT_PRBS_SYNC_STATUS_NOTCONFIGURED     = 0, ///< NOTCONFIGURED
    IFCS_DEVPORT_PRBS_SYNC_STATUS_LINK_DOWN         = 1, ///< LINK_DOWN
    IFCS_DEVPORT_PRBS_SYNC_STATUS_IN_PROGRESS       = 2, ///< IN_PROGRESS
    IFCS_DEVPORT_PRBS_SYNC_STATUS_SYNC              = 3, ///< SYNC
    IFCS_DEVPORT_PRBS_SYNC_STATUS_NO_SYNC           = 4, ///< NO_SYNC
    IFCS_DEVPORT_PRBS_SYNC_STATUS_LINK_DOWN_SYNC    = 5, ///< LINK_DOWN_SYNC
    IFCS_DEVPORT_PRBS_SYNC_STATUS_LINK_DOWN_NO_SYNC = 6, ///< LINK_DOWN_NO_SYNC
} ifcs_devport_prbs_sync_status_t;

/**
 * @brief RX tune effort
 */
typedef enum ifcs_devport_rx_tune_effort_e {
    IFCS_DEVPORT_RX_TUNE_EFFORT_LOW    = 0x0,  ///< LOW
    IFCS_DEVPORT_RX_TUNE_EFFORT_MEDIUM = 0x10, ///< MEDIUM
    IFCS_DEVPORT_RX_TUNE_EFFORT_HIGH   = 0x1,  ///< HIGH
} ifcs_devport_rx_tune_effort_t;

/**
 * @brief Lane speed
 */
typedef enum ifcs_lane_speed_e {
    IFCS_LANE_SPEED_INVALID = 0, ///< INVALID
    IFCS_LANE_SPEED_10G     = 1, ///< 10G
    IFCS_LANE_SPEED_25G     = 2, ///< 25G
    IFCS_LANE_SPEED_50G     = 3, ///< 50G
} ifcs_lane_speed_t;

/**
 * @brief Device port
 */
typedef enum ifcs_devport_attr_id_e {
    /**
     * @brief Port Type
     *
     * type = ifcs_devport_type_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = CREATE_ONLY | MANDATORY_ON_CREATE
     */
    IFCS_DEVPORT_ATTR_TYPE                              = 0,

    /**
     * @brief SerDes group for dev port
     *
     * type = ifcs_devport_serdes_group_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = CREATE_ONLY | MANDATORY_ON_CREATE
     */
    IFCS_DEVPORT_ATTR_SERDES_GROUP                      = 1,

    /**
     * @brief IB number
     *
     * type = ifcs_ib_t (use ifcs_attr_t_value_ib_set()/ifcs_attr_t_value_ib_get())
     * flags = GET_ONLY
     */
    IFCS_DEVPORT_ATTR_IB                                = 2,

    /**
     * @brief IB port number. This is an optional create-only attribute for ETH ports. For other port types, it is a read-only attribute
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = CREATE_ONLY
     * default = Use GET API
     */
    IFCS_DEVPORT_ATTR_IBPORT                            = 3,

    /**
     * @brief PIC number
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = GET_ONLY
     */
    IFCS_DEVPORT_ATTR_PIC                               = 4,

    /**
     * @brief start lane for dev port
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = CREATE_ONLY | MANDATORY_ON_CREATE
     */
    IFCS_DEVPORT_ATTR_START_LANE                        = 5,

    /**
     * @brief number of lanes for dev port
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = CREATE_ONLY | MANDATORY_ON_CREATE
     */
    IFCS_DEVPORT_ATTR_NUM_LANES                         = 6,

    /**
     * @brief sysport
     *
     * type = ifcs_handle_t (use ifcs_attr_t_value_handle_set()/ifcs_attr_t_value_handle_get())
     * objects = IFCS Objects of (
     *          module = IFCS_MOD_SYSPORT and object = IFCS_API_CLASS_SYSPORT)
     * flags = CREATE_ONLY | MANDATORY_ON_CREATE
     */
    IFCS_DEVPORT_ATTR_SYSPORT                           = 7,

    /**
     * @brief Speed in Gbps
     *
     * type = ifcs_devport_speed_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = MANDATORY when (
     *          IFCS_DEVPORT_ATTR_AUTO_NEG = FALSE) |
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_TX_RF_TRANSMIT_ENABLE is TRUE)
     */
    IFCS_DEVPORT_ATTR_SPEED                             = 8,

    /**
     * @brief Operational Status
     *
     * type = ifcs_devport_link_status_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = GET_ONLY
     */
    IFCS_DEVPORT_ATTR_LINK_STATUS                       = 9,

    /**
     * @brief Local fault Status
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = GET_ONLY
     */
    IFCS_DEVPORT_ATTR_LOCAL_FAULT                       = 10,

    /**
     * @brief Remote fault Status
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = GET_ONLY
     */
    IFCS_DEVPORT_ATTR_REMOTE_FAULT                      = 11,

    /**
     * @brief PCS link Status
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = GET_ONLY
     */
    IFCS_DEVPORT_ATTR_PCS_STATUS                        = 12,

    /**
     * @brief Devport FSM state
     *
     * type = ifcs_devport_state_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = GET_ONLY
     */
    IFCS_DEVPORT_ATTR_OPER_STATE                        = 13,

    /**
     * @brief FEC mode
     *
     * type = ifcs_devport_fec_mode_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = MANDATORY when (
     *          IFCS_DEVPORT_ATTR_AUTO_NEG = FALSE)
     */
    IFCS_DEVPORT_ATTR_FEC_MODE                          = 14,

    /**
     * @brief Loopback modes
     *
     * type = ifcs_devport_loopback_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_TX_RF_TRANSMIT_ENABLE is TRUE)
     * default = (NONE)
     */
    IFCS_DEVPORT_ATTR_LOOPBACK                          = 15,

    /**
     * @brief Auto Negotiation configuration
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_TX_RF_TRANSMIT_ENABLE is TRUE)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_AUTO_NEG                          = 16,

    /**
     * @brief Auto Negotiation local device base page tech ability
     *
     * type = ifcs_devport_an_bp_tech_ability_list_t (use ifcs_attr_t_value_devport_an_bp_tech_ability_list_set()/ifcs_attr_t_value_devport_an_bp_tech_ability_list_get())
     * flags = MANDATORY when (
     *          IFCS_DEVPORT_ATTR_AUTO_NEG = TRUE) |
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_TX_RF_TRANSMIT_ENABLE is TRUE)
     * default = (NONE)
     */
    IFCS_DEVPORT_ATTR_AUTO_NEG_LD_BP_TECH_ABILITY       = 17,

    /**
     * @brief Auto Negotiation completion status
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags = GET_ONLY
     */
    IFCS_DEVPORT_ATTR_AUTO_NEG_COMPLETE                 = 18,

    /**
     * @brief Auto Negotiation HCD resolution
     *
     * type = ifcs_devport_an_bp_tech_ability_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = GET_ONLY
     */
    IFCS_DEVPORT_ATTR_AUTO_NEG_HCD_RESOLUTION           = 19,

    /**
     * @brief Auto Negotiation link partner base page tech ability
     *
     * type = ifcs_devport_an_bp_tech_ability_list_t (use ifcs_attr_t_value_devport_an_bp_tech_ability_list_set()/ifcs_attr_t_value_devport_an_bp_tech_ability_list_get())
     * flags = GET_ONLY
     */
    IFCS_DEVPORT_ATTR_AUTO_NEG_LP_BP_TECH_ABILITY       = 20,

    /**
     * @brief Link Training enable/disable
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_TX_RF_TRANSMIT_ENABLE is TRUE)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_LINK_TRAINING                     = 21,

    /**
     * @brief Link training restart delay timer (value in ms)
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (3200)
     */
    IFCS_DEVPORT_ATTR_LINK_TRAINING_RESTART_DELAY_TIMER = 22,

    /**
     * @brief Admin Mode
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_ADMIN_STATE                       = 23,

    /**
     * @brief PCS test pattern enable/disable
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PCS_TEST_PATTERN                  = 24,

    /**
     * @brief PRBS generator polynomial
     *
     * type = ifcs_devport_serdes_polynomial_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (NOTCONFIGURED)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_GENERATOR_POLY               = 25,

    /**
     * @brief PRBS TX rate
     *
     * type = ifcs_devport_serdes_prbs_rate_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (NOTCONFIGURED)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_TX_RATE                      = 26,

    /**
     * @brief Start PRBS TX generator
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags = MANDATORY when (
     *          IFCS_DEVPORT_ATTR_PRBS_TX_RATE or
     *          IFCS_DEVPORT_ATTR_PRBS_GENERATOR_POLY)
     * default = (FALSE)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_GENERATOR                    = 27,

    /**
     * @brief PRBS checker polynomial
     *
     * type = ifcs_devport_serdes_polynomial_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (NOTCONFIGURED)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_CHECKER_POLY                 = 28,

    /**
     * @brief PRBS RX rate
     *
     * type = ifcs_devport_serdes_prbs_rate_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (NOTCONFIGURED)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_RX_RATE                      = 29,

    /**
     * @brief PRBS RX comparator
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_COMPARATOR                   = 30,

    /**
     * @brief Start PRBS Rx checker
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags = MANDATORY when (
     *          IFCS_DEVPORT_ATTR_PRBS_RX_RATE or
     *          IFCS_DEVPORT_ATTR_PRBS_CHECKER_POLY)
     * default = (FALSE)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_CHECKER                      = 31,

    /**
     * @brief PRBS loopback mode
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_ILB                          = 32,

    /**
     * @brief PRBS mode
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_MODE_ENABLE                  = 33,

    /**
     * @brief PRBS set
     *
     * type = ifcs_devport_prbs_mode_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (NOTCONFIGURED)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_SET                          = 34,

    /**
     * @brief PRBS sync
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_SYNC                         = 35,

    /**
     * @brief PRBS compare time in ms
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_COMPARE_TIME                 = 36,

    /**
     * @brief PRBS error count
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_ERR_COUNT_LIMIT              = 37,

    /**
     * @brief PRBS error count
     *
     * type = ifcs_flt_t (use ifcs_attr_t_value_flt_set()/ifcs_attr_t_value_flt_get())
     * default = Use GET API
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_BER_LIMIT                    = 38,

    /**
     * @brief PRBS error count
     *
     * type = ifcs_u32_list_t (use ifcs_attr_t_value_u32_list_set()/ifcs_attr_t_value_u32_list_get())
     * flags = CREATE_ONLY
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_ERR_COUNT                    = 39,

    /**
     * @brief PRBS BER
     *
     * type = ifcs_flt_list_t (use ifcs_attr_t_value_flt_list_set()/ifcs_attr_t_value_flt_list_get())
     * flags = CREATE_ONLY
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_BER                          = 40,

    /**
     * @brief PRBS sync status
     *
     * type = ifcs_u32_list_t (use ifcs_attr_t_value_u32_list_set()/ifcs_attr_t_value_u32_list_get())
     * flags = CREATE_ONLY
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_PRBS_SYNC_STATUS                  = 41,

    /**
     * @brief Bitmap of serdes lanes in the port
     *
     * type = ifcs_uint8_t (use ifcs_attr_t_value_u8_set()/ifcs_attr_t_value_u8_get())
     * range =  max: 255
     * default = Use GET API
     */
    IFCS_DEVPORT_ATTR_LANE_MASK                         = 42,

    /**
     * @brief TX pre1 equalization
     *
     * type = ifcs_i8_list_t (use ifcs_attr_t_value_i8_list_set()/ifcs_attr_t_value_i8_list_get())
     * default = (0)
     */
    IFCS_DEVPORT_ATTR_TX_EQ_PRE1                        = 43,

    /**
     * @brief TX pre2 equalization
     *
     * type = ifcs_i8_list_t (use ifcs_attr_t_value_i8_list_set()/ifcs_attr_t_value_i8_list_get())
     * default = (0)
     */
    IFCS_DEVPORT_ATTR_TX_EQ_PRE2                        = 44,

    /**
     * @brief TX pre3 equalization
     *
     * type = ifcs_i8_list_t (use ifcs_attr_t_value_i8_list_set()/ifcs_attr_t_value_i8_list_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_TX_EQ_PRE3                        = 45,

    /**
     * @brief TX attenuation
     *
     * type = ifcs_i8_list_t (use ifcs_attr_t_value_i8_list_set()/ifcs_attr_t_value_i8_list_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_TX_EQ_ATTN                        = 46,

    /**
     * @brief TX post attenuation
     *
     * type = ifcs_i8_list_t (use ifcs_attr_t_value_i8_list_set()/ifcs_attr_t_value_i8_list_get())
     * default = (0)
     */
    IFCS_DEVPORT_ATTR_TX_EQ_POST                        = 47,

    /**
     * @brief Tx PLL loop bandwidth frequency
     *
     * type = ifcs_tx_bw_freq_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = CREATE_ONLY
     * default = (NOTCONFIGURED)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_TX_PLL_BW_FREQ                    = 48,

    /**
     * @brief RX equalization fine tune
     *
     * type = ifcs_devport_serdes_rx_eq_fine_tune_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (CONTINUOUS)
     */
    IFCS_DEVPORT_ATTR_RX_EQ_FINE_TUNE                   = 49,

    /**
     * @brief Rx CTLE LF
     *
     * type = ifcs_u8_list_t (use ifcs_attr_t_value_u8_list_set()/ifcs_attr_t_value_u8_list_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_CTLE_LF                        = 50,

    /**
     * @brief Rx CTLE HF
     *
     * type = ifcs_u8_list_t (use ifcs_attr_t_value_u8_list_set()/ifcs_attr_t_value_u8_list_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_CTLE_HF                        = 51,

    /**
     * @brief Rx CTLE BW
     *
     * type = ifcs_u8_list_t (use ifcs_attr_t_value_u8_list_set()/ifcs_attr_t_value_u8_list_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_CTLE_BW                        = 52,

    /**
     * @brief Rx CTLE gainshape1
     *
     * type = ifcs_u32_list_t (use ifcs_attr_t_value_u32_list_set()/ifcs_attr_t_value_u32_list_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_GAINSHAPE1                     = 53,

    /**
     * @brief Rx CTLE gainshape2
     *
     * type = ifcs_u32_list_t (use ifcs_attr_t_value_u32_list_set()/ifcs_attr_t_value_u32_list_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_GAINSHAPE2                     = 54,

    /**
     * @brief Rx AGC target
     *
     * type = ifcs_u32_list_t (use ifcs_attr_t_value_u32_list_set()/ifcs_attr_t_value_u32_list_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_AGC_TARGET                     = 55,

    /**
     * @brief Rx eye disqualify threshold 25G
     *
     * type = ifcs_u32_list_t (use ifcs_attr_t_value_u32_list_set()/ifcs_attr_t_value_u32_list_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_EYE_DISQUALIFY_THRESHOLD_25G   = 56,

    /**
     * @brief Rx coarse tune effort 10G; not applied when link training is enabled
     *
     * type = ifcs_devport_rx_tune_effort_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (MEDIUM)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_EQ_COARSE_TUNE_EFFORT_10G      = 57,

    /**
     * @brief Rx coarse tune effort 25G; not applied when link training is enabled
     *
     * type = ifcs_devport_rx_tune_effort_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (LOW)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_EQ_COARSE_TUNE_EFFORT_25G      = 58,

    /**
     * @brief Rx coarse tune effort 50G; not applied when link training is enabled
     *
     * type = ifcs_devport_rx_tune_effort_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (MEDIUM)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_EQ_COARSE_TUNE_EFFORT_50G      = 59,

    /**
     * @brief Rx fine tune effort 10G
     *
     * type = ifcs_devport_rx_tune_effort_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (HIGH)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_EQ_FINE_TUNE_EFFORT_10G        = 60,

    /**
     * @brief Rx fine tune effort 25G
     *
     * type = ifcs_devport_rx_tune_effort_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (LOW)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_EQ_FINE_TUNE_EFFORT_25G        = 61,

    /**
     * @brief Rx fine tune effort 50G
     *
     * type = ifcs_devport_rx_tune_effort_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (HIGH)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_EQ_FINE_TUNE_EFFORT_50G        = 62,

    /**
     * @brief SD RX retune enable
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_RETUNE_ENABLE                  = 63,

    /**
     * @brief SD RX DFE retune vertical eye height threshold at 1e-06 BER (mV)
     *
     * type = ifcs_int32_t (use ifcs_attr_t_value_int32_set()/ifcs_attr_t_value_int32_get())
     * default = Use GET API
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_RETUNE_THRESHOLD_1E_MINUS_06   = 64,

    /**
     * @brief SD RX DFE retune vertical eye height threshold at 1e-15 BER (mV)
     *
     * type = ifcs_int32_t (use ifcs_attr_t_value_int32_set()/ifcs_attr_t_value_int32_get())
     * default = Use GET API
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_RETUNE_THRESHOLD_1E_MINUS_15   = 65,

    /**
     * @brief SD RX retune reset threshold
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (5)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_RETUNE_RESET_THRESHOLD         = 66,

    /**
     * @brief SD RX DVOS offset 50G
     *
     * type = ifcs_i32_list_t (use ifcs_attr_t_value_i32_list_set()/ifcs_attr_t_value_i32_list_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_DVOS_OFFSET_50G                = 67,

    /**
     * @brief SD RX auto HF post 50G
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_AUTO_HF_POST_50G               = 68,

    /**
     * @brief SD RX HF post positive threshold 50G
     *
     * type = ifcs_i32_list_t (use ifcs_attr_t_value_i32_list_set()/ifcs_attr_t_value_i32_list_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_HF_POST_POSITIVE_THRESHOLD_50G = 69,

    /**
     * @brief SD RX HF post negative threshold 50G
     *
     * type = ifcs_i32_list_t (use ifcs_attr_t_value_i32_list_set()/ifcs_attr_t_value_i32_list_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_RX_HF_POST_NEGATIVE_THRESHOLD_50G = 70,

    /**
     * @brief Signal detect mode
     *
     * type = ifcs_devport_signal_detect_mode_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (MODE1)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_SIG_DET_MODE                      = 71,

    /**
     * @brief Signal detect delay timer (value in ms)
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_SIG_DET_DELAY_TIMER               = 72,

    /**
     * @brief TX remote fault transmit enable
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_TX_RF_TRANSMIT_ENABLE             = 73,

    /**
     * @brief SD TX output enable
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (TRUE)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_SD_TX_OUTPUT_ENABLE               = 74,

    /**
     * @brief SD reset enable 25G
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (TRUE)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_SD_RESET_25G                      = 75,

    /**
     * @brief SD reset threshold 25G, number of SD retunes before reset
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_SD_RESET_THRESHOLD_25G            = 76,

    /**
     * @brief Inter packet gap
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * range =  min: 12 max: 60
     * flags = CREATE_ONLY
     * default = (12)
     */
    IFCS_DEVPORT_ATTR_IPG                               = 77,

    /**
     * @brief This mode determines whether the PFC enable controls on a devport are split out into separate TX and RX attributes (per PFC codepoint) or combined into a single attribute (per PFC codepoint).
     * IFCS_DEVPORT_ATTR_PFC<0-7>_TX_ENABLE and IFCS_DEVPORT_ATTR_PFC<0-7>_RX_ENABLE are valid when mode is SEPARATE.
     * IFCS_DEVPORT_ATTR_PFC<0-7>_ENABLE is valid when the mode is COMBINED.
     *
     *
     * type = ifcs_devport_pfc_mode_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (COMBINED)
     */
    IFCS_DEVPORT_ATTR_PFC_MODE                          = 78,

    /**
     * @brief Enable/disable TX and RX of PFC for PFC Code Point 0
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is SEPARATE)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC0_ENABLE                       = 79,

    /**
     * @brief Enable/disable TX and RX of PFC for PFC Code Point 1
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is SEPARATE)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC1_ENABLE                       = 80,

    /**
     * @brief Enable/disable TX and RX of PFC for PFC Code Point 2
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is SEPARATE)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC2_ENABLE                       = 81,

    /**
     * @brief Enable/disable TX and RX of PFC for PFC Code Point 3
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is SEPARATE)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC3_ENABLE                       = 82,

    /**
     * @brief Enable/disable TX and RX of PFC for PFC Code Point 4
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is SEPARATE)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC4_ENABLE                       = 83,

    /**
     * @brief Enable/disable TX and RX of PFC for PFC Code Point 5
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is SEPARATE)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC5_ENABLE                       = 84,

    /**
     * @brief Enable/disable TX and RX of PFC for PFC Code Point 6
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is SEPARATE)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC6_ENABLE                       = 85,

    /**
     * @brief Enable/disable TX and RX of PFC for PFC Code Point 7
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is SEPARATE)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC7_ENABLE                       = 86,

    /**
     * @brief Enable/disable TX of PFC for PFC Code Point 0
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC0_TX_ENABLE                    = 87,

    /**
     * @brief Enable/disable TX of PFC for PFC Code Point 1
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC1_TX_ENABLE                    = 88,

    /**
     * @brief Enable/disable TX of PFC for PFC Code Point 2
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC2_TX_ENABLE                    = 89,

    /**
     * @brief Enable/disable TX of PFC for PFC Code Point 3
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC3_TX_ENABLE                    = 90,

    /**
     * @brief Enable/disable TX of PFC for PFC Code Point 4
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC4_TX_ENABLE                    = 91,

    /**
     * @brief Enable/disable TX of PFC for PFC Code Point 5
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC5_TX_ENABLE                    = 92,

    /**
     * @brief Enable/disable TX of PFC for PFC Code Point 6
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC6_TX_ENABLE                    = 93,

    /**
     * @brief Enable/disable TX of PFC for PFC Code Point 7
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC7_TX_ENABLE                    = 94,

    /**
     * @brief Enable/disable RX of PFC for PFC Code Point 0
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC0_RX_ENABLE                    = 95,

    /**
     * @brief Enable/disable RX of PFC for PFC Code Point 1
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC1_RX_ENABLE                    = 96,

    /**
     * @brief Enable/disable RX of PFC for PFC Code Point 2
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC2_RX_ENABLE                    = 97,

    /**
     * @brief Enable/disable RX of PFC for PFC Code Point 3
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC3_RX_ENABLE                    = 98,

    /**
     * @brief Enable/disable RX of PFC for PFC Code Point 4
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC4_RX_ENABLE                    = 99,

    /**
     * @brief Enable/disable RX of PFC for PFC Code Point 5
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC5_RX_ENABLE                    = 100,

    /**
     * @brief Enable/disable RX of PFC for PFC Code Point 6
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC6_RX_ENABLE                    = 101,

    /**
     * @brief Enable/disable RX of PFC for PFC Code Point 7
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC7_RX_ENABLE                    = 102,

    /**
     * @brief Specifies link length(in meters) associated with devport. Used to compute buffer settings for lossless frame delivery.
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * range =  min: 10 max: 10000
     * flags = CREATE_ONLY
     * default = (10)
     */
    IFCS_DEVPORT_ATTR_LINK_LENGTH                       = 103,

    /**
     * @brief Enable/disable the max-rate shaper
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_MAX_RATE_ENABLE                   = 104,

    /**
     * @brief Maximum transmit rate, specified in bits per sec; applicable to non-CPU ports. Maximum possible rate is port speed.
     *
     * type = ifcs_uint64_t (use ifcs_attr_t_value_u64_set()/ifcs_attr_t_value_u64_get())
     * range =  min: 62500
     * flags = MANDATORY when (
     *          IFCS_DEVPORT_ATTR_MAX_RATE_ENABLE = TRUE)
     */
    IFCS_DEVPORT_ATTR_MAX_RATE                          = 105,

    /**
     * @brief Maximum burst size, specified in bytes; applicable to non-CPU ports
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * range =  min: 1 max: 2000000000
     * default = (16777216)
     */
    IFCS_DEVPORT_ATTR_MAX_BURST_SIZE                    = 106,

    /**
     * @brief Actual maximum transmit rate, in bits per sec; applicable to non-CPU ports. Valid when devport max_rate_enable is set.
     *
     * type = ifcs_uint64_t (use ifcs_attr_t_value_u64_set()/ifcs_attr_t_value_u64_get())
     * flags = GET_ONLY
     */
    IFCS_DEVPORT_ATTR_ACTUAL_MAX_RATE                   = 107,

    /**
     * @brief Actual maximum burst size, in bytes; applicable to non-CPU ports
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = GET_ONLY
     */
    IFCS_DEVPORT_ATTR_ACTUAL_MAX_BURST_SIZE             = 108,

    /**
     * @brief Enable/disable the CPU max-rate shaper
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_CPU_MAX_RATE_ENABLE               = 109,

    /**
     * @brief Maximum transmit rate to CPU port, specified in packets per second
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * range =  min: 122 max: 60000000
     * flags = MANDATORY when (
     *          IFCS_DEVPORT_ATTR_CPU_MAX_RATE_ENABLE = TRUE)
     */
    IFCS_DEVPORT_ATTR_CPU_MAX_RATE                      = 110,

    /**
     * @brief Maximum burst size to CPU port, specified in packets
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * range =  min: 1 max: 1000000000
     * default = (1000000)
     */
    IFCS_DEVPORT_ATTR_CPU_MAX_BURST_SIZE                = 111,

    /**
     * @brief Actual maximum transmit rate to CPU port, in packets per second. Valid when cpu_max_rate_enable is set
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = GET_ONLY
     */
    IFCS_DEVPORT_ATTR_ACTUAL_CPU_MAX_RATE               = 112,

    /**
     * @brief Actual maximum burst size to CPU port, in packets
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = GET_ONLY
     */
    IFCS_DEVPORT_ATTR_ACTUAL_CPU_MAX_BURST_SIZE         = 113,

    /**
     * @brief Enable/disable cut through mode
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_CUT_THROUGH_ENABLE                = 114,

    /**
     * @brief Enable/disable PFC watchdog on this devport
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC_WD_ENABLE                     = 115,

    /**
     * @brief Specifies the mitigation action if PFC storm is detected on this devport's queues
     *
     * type = ifcs_pfc_wd_mitigation_action_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (FORWARD)
     */
    IFCS_DEVPORT_ATTR_PFC_WD_MITIGATION_ACTION          = 116,

    /**
     * @brief Specifies the restoration mode
     *
     * type = ifcs_pfc_wd_restoration_mode_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (AUTO)
     */
    IFCS_DEVPORT_ATTR_PFC_WD_RESTORATION_MODE           = 117,

    /**
     * @brief Trigger the PFC watchdog manual restoration. Valid only if pfc_wd_restoration_mode is MANUAL
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PFC_WD_RESTORATION_MODE is AUTO or
     *          IFCS_DEVPORT_ATTR_PFC_WD_RESTORATION_MODE is FORCE)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PFC_WD_MANUAL_RESTORATION_TRIGGER = 118,

    /**
     * @brief Specifies the PFC watchdog detection threshold in milli-seconds
     *
     * type = ifcs_uint16_t (use ifcs_attr_t_value_u16_set()/ifcs_attr_t_value_u16_get())
     * range =  min: 10 max: 10000
     * default = (100)
     */
    IFCS_DEVPORT_ATTR_PFC_WD_DETECTION_THRESHOLD        = 119,

    /**
     * @brief Specifies the PFC watchdog restoration threshold in milli-seconds
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * range =  min: 10 max: 100000
     * default = (5000)
     */
    IFCS_DEVPORT_ATTR_PFC_WD_RESTORATION_THRESHOLD      = 120,

    /**
     * @brief Serdes Low Power Mode configuration
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_SD_LOW_POWER_MODE                 = 121,

    /**
     * @brief Serdes Low Power Mode Operational Status
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags = GET_ONLY
     * device restrictions = supported on IFCS_DEVICE_TERALYNX7
     */
    IFCS_DEVPORT_ATTR_SD_LOW_POWER_MODE_STATUS          = 122,

    /**
     * @brief Timer to wait for link UP before Auto neg restart (value in ms)
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (500)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX5
     */
    IFCS_DEVPORT_ATTR_AUTO_NEG_LINK_UP_WAIT_TIMER       = 123,

    /**
     * @brief TX main equalization
     *
     * type = ifcs_i8_list_t (use ifcs_attr_t_value_i8_list_set()/ifcs_attr_t_value_i8_list_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX5
     */
    IFCS_DEVPORT_ATTR_TX_EQ_MAIN                        = 124,

    /**
     * @brief TX post2 attenuation
     *
     * type = ifcs_i8_list_t (use ifcs_attr_t_value_i8_list_set()/ifcs_attr_t_value_i8_list_get())
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX5
     */
    IFCS_DEVPORT_ATTR_TX_EQ_POST2                       = 125,

    /**
     * @brief SD optical mode
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (FALSE)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX5
     */
    IFCS_DEVPORT_ATTR_SD_OPTICAL_MODE                   = 126,

    /**
     * @brief Enable/disable PTP on this devport for PTP instance
     *
     * type = ifcs_ptp_policy_t (use ifcs_attr_t_value_ptp_policy_set()/ifcs_attr_t_value_ptp_policy_get())
     * default = Use GET API
     * device restrictions = supported on IFCS_DEVICE_TERALYNX5
     */
    IFCS_DEVPORT_ATTR_PTP_POLICY                        = 127,

    /**
     * @brief The peer mean path delay between the source port and the peer, that shall be added to correction-field along with resident time. Applicable only if ptp_instance type == P2P_TRANSPARENT_CLOCK
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * range =  max: 65535
     * default = (0)
     * device restrictions = supported on IFCS_DEVICE_TERALYNX5
     */
    IFCS_DEVPORT_ATTR_PTP_PEER_MEAN_PATH_DELAY_ADD_NS   = 128,

    /**
     * @brief Max PIC software actionable interrupts per second (0 = throttling is disabled)
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (5)
     */
    IFCS_DEVPORT_ATTR_PIC_INTRS_LIMIT_PER_SECOND        = 129,

    /**
     * @brief Delay re-enabling of software actionable PIC interrupts when limit reached (in seconds, 0 = throttling is disabled)
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (2)
     */
    IFCS_DEVPORT_ATTR_PIC_INTRS_WAIT_INTERVAL           = 130,

    /**
     * @brief Specifies the assumed network MTU. Value used to set the lossless inflight buffer size.  Options include: 1518, 2500, 9216
     *
     *
     * type = ifcs_uint32_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = CREATE_ONLY
     * default = (9216)
     */
    IFCS_DEVPORT_ATTR_LL_NETWORK_MTU                    = 131,

    /**
     * @brief This mode determines whether the Pause enable controls on a devport are split out into separate TX and RX attributes or combined into a single attribute.
     * IFCS_DEVPORT_ATTR_PAUSE_TX_ENABLE and IFCS_DEVPORT_ATTR_PAUSE_RX_ENABLE are valid when mode is SEPARATE.
     * IFCS_DEVPORT_ATTR_PAUSE_ENABLE is valid when the mode is COMBINED.
     *
     *
     * type = ifcs_devport_pause_mode_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * default = (COMBINED)
     */
    IFCS_DEVPORT_ATTR_PAUSE_MODE                        = 132,

    /**
     * @brief Enable/disable TX and RX of Pause
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PAUSE_MODE is SEPARATE)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PAUSE_ENABLE                      = 133,

    /**
     * @brief Enable/disable TX of Pause
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PAUSE_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PAUSE_TX_ENABLE                   = 134,

    /**
     * @brief Enable/disable RX of Pause
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_PAUSE_MODE is COMBINED)
     * default = (FALSE)
     */
    IFCS_DEVPORT_ATTR_PAUSE_RX_ENABLE                   = 135,

    /**
     * @brief Reserved for future use
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * flags = GET_ONLY
     * default = (false)
     */
    IFCS_DEVPORT_ATTR_RESERVED14_1                      = 136,

    /**
     * @brief Enable/Disable transmission of data packets from a port
     *
     * type = ifcs_bool_t (use ifcs_attr_t_value_data_set()/ifcs_attr_t_value_data_get())
     * default = (TRUE)
     */
    IFCS_DEVPORT_ATTR_PKT_TX_ENABLE                     = 137,

    /**
     * @brief Rx FFE PRE1 min
     *
     * type = ifcs_u8_list_t (use ifcs_attr_t_value_u8_list_set()/ifcs_attr_t_value_u8_list_get())
     * range =  max: 15
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_LANE_SPEED is 10G or
     *          IFCS_DEVPORT_ATTR_LANE_SPEED is 25G)
     * default = (0)
     */
    IFCS_DEVPORT_ATTR_RX_FFE_PRE1_MIN                   = 138,

    /**
     * @brief Rx FFE PRE1 max
     *
     * type = ifcs_u8_list_t (use ifcs_attr_t_value_u8_list_set()/ifcs_attr_t_value_u8_list_get())
     * range =  max: 15
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_LANE_SPEED is 10G or
     *          IFCS_DEVPORT_ATTR_LANE_SPEED is 25G)
     * default = (15)
     */
    IFCS_DEVPORT_ATTR_RX_FFE_PRE1_MAX                   = 139,

    /**
     * @brief Rx FFE PRE2 min
     *
     * type = ifcs_i8_list_t (use ifcs_attr_t_value_i8_list_set()/ifcs_attr_t_value_i8_list_get())
     * range =  min: -10 max: 10
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_LANE_SPEED is 10G or
     *          IFCS_DEVPORT_ATTR_LANE_SPEED is 25G)
     * default = (-10)
     */
    IFCS_DEVPORT_ATTR_RX_FFE_PRE2_MIN                   = 140,

    /**
     * @brief Rx FFE PRE2 max
     *
     * type = ifcs_i8_list_t (use ifcs_attr_t_value_i8_list_set()/ifcs_attr_t_value_i8_list_get())
     * range =  min: -10 max: 10
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_LANE_SPEED is 10G or
     *          IFCS_DEVPORT_ATTR_LANE_SPEED is 25G)
     * default = (10)
     */
    IFCS_DEVPORT_ATTR_RX_FFE_PRE2_MAX                   = 141,

    /**
     * @brief Rx FFE post1 min
     *
     * type = ifcs_i8_list_t (use ifcs_attr_t_value_i8_list_set()/ifcs_attr_t_value_i8_list_get())
     * range =  min: -15 max: 15
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_LANE_SPEED is 10G or
     *          IFCS_DEVPORT_ATTR_LANE_SPEED is 25G)
     * default = (-3)
     */
    IFCS_DEVPORT_ATTR_RX_FFE_POST1_MIN                  = 142,

    /**
     * @brief Rx FFE post1 max
     *
     * type = ifcs_i8_list_t (use ifcs_attr_t_value_i8_list_set()/ifcs_attr_t_value_i8_list_get())
     * range =  min: -15 max: 15
     * flags =
     *        INVALID_ATTRIBUTE when (
     *          IFCS_DEVPORT_ATTR_LANE_SPEED is 10G or
     *          IFCS_DEVPORT_ATTR_LANE_SPEED is 25G)
     * default = (8)
     */
    IFCS_DEVPORT_ATTR_RX_FFE_POST1_MAX                  = 143,

    /**
     * @brief Devport mode
     *
     * type = ifcs_lane_speed_t (use ifcs_attr_t_value_u32_set()/ifcs_attr_t_value_u32_get())
     * flags = GET_ONLY
     * default = Use GET API
     */
    IFCS_DEVPORT_ATTR_LANE_SPEED                        = 144,

    /**
     * @brief List of supported speeds on the devport with current config
     *
     * type = ifcs_devport_speed_list_t (use ifcs_attr_t_value_devport_speed_list_set()/ifcs_attr_t_value_devport_speed_list_get())
     * flags = GET_ONLY
     * default = (0)
     */
    IFCS_DEVPORT_ATTR_SUPPORTED_SPEED                   = 145,

    /**
     * @brief List of supported FEC modess on the devport with current config
     *
     * type = ifcs_u32_list_t (use ifcs_attr_t_value_u32_list_set()/ifcs_attr_t_value_u32_list_get())
     * flags = GET_ONLY
     * default = (0)
     */
    IFCS_DEVPORT_ATTR_SUPPORTED_FEC_MODE                = 146,

    /**
     * @brief List of supported auto-neg tech ability on the devport with current config
     *
     * type = ifcs_devport_an_bp_tech_ability_list_t (use ifcs_attr_t_value_devport_an_bp_tech_ability_list_set()/ifcs_attr_t_value_devport_an_bp_tech_ability_list_get())
     * flags = GET_ONLY
     * default = (0)
     */
    IFCS_DEVPORT_ATTR_SUPPORTED_AN_TECH_ABILITY         = 147,

    /**
     * @brief MAX attribute
     */
    IFCS_DEVPORT_ATTR_MAX_COUNT                         = 148,
} ifcs_devport_attr_id_t;

/*
 * Use this to get all the attributes in devport
 */
#define IFCS_DEVPORT_ATTR_COUNT_GET_ALL    (IFCS_DEVPORT_ATTR_MAX_COUNT + 1)

/**
 * @brief Stats for devport API class
 */
typedef enum ifcs_devport_stats_id_e {
    /**
     * @brief Number of frames received; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_ALL                     = 0,

    /**
     * @brief Number of frames received without any error; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_OK                      = 1,

    /**
     * @brief Number of received frames dropped; valid for CPU port only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_DROP                    = 2,

    /**
     * @brief Number of frames received with unicast address; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_UNICAST                 = 3,

    /**
     * @brief Number of frames received with multicast address; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_MULTICAST               = 4,

    /**
     * @brief Number of frames received with broadcast address; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_BROADCAST               = 5,

    /**
     * @brief Number of frames received with Pause type; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_PAUSE                   = 6,

    /**
     * @brief Number of frames received that were Priority Flow Control frames; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_PFC                     = 7,

    /**
     * @brief Number of frames received that were VLAN tagged and had no CRC error; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_VLAN                    = 8,

    /**
     * @brief Number of frames received that were shorter than 64 bytes; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_LEN_LT_64               = 9,

    /**
     * @brief Number of frames received that were 64 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_LEN_64                  = 10,

    /**
     * @brief Number of frames received that were 65 to 127 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_LEN_65_127              = 11,

    /**
     * @brief Number of frames received that were 128 to 255 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_LEN_128_255             = 12,

    /**
     * @brief Number of frames received that were 256 to 511 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_LEN_256_511             = 13,

    /**
     * @brief Number of frames received that were 512 to 1023 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_LEN_512_1023            = 14,

    /**
     * @brief Number of frames received that were 1024 to 1518 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_LEN_1024_1518           = 15,

    /**
     * @brief Number of frames received that were 1519 to 2047 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_LEN_1519_2047           = 16,

    /**
     * @brief Number of frames received that were 2048 to 4095 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_LEN_2048_4095           = 17,

    /**
     * @brief Number of frames received that were 4096 to 8191 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_LEN_4096_8191           = 18,

    /**
     * @brief Number of frames received that were 8192 to 9215 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_LEN_8192_9215           = 19,

    /**
     * @brief Number of frames received that were longer than 9215 bytes; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_LEN_GE_9216             = 20,

    /**
     * @brief Number of PFC frames received with priority0 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_PFC0                    = 21,

    /**
     * @brief Number of PFC frames received with priority1 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_PFC1                    = 22,

    /**
     * @brief Number of PFC frames received with priority2 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_PFC2                    = 23,

    /**
     * @brief Number of PFC frames received with priority3 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_PFC3                    = 24,

    /**
     * @brief Number of PFC frames received with priority4 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_PFC4                    = 25,

    /**
     * @brief Number of PFC frames received with priority5 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_PFC5                    = 26,

    /**
     * @brief Number of PFC frames received with priority6 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_PFC6                    = 27,

    /**
     * @brief Number of PFC frames received with priority7 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_PFC7                    = 28,

    /**
     * @brief Time when received PFC priority0 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_TIME_PFC0                      = 29,

    /**
     * @brief Time when received PFC priority1 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_TIME_PFC1                      = 30,

    /**
     * @brief Time when received PFC priority2 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_TIME_PFC2                      = 31,

    /**
     * @brief Time when received PFC priority3 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_TIME_PFC3                      = 32,

    /**
     * @brief Time when received PFC priority4 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_TIME_PFC4                      = 33,

    /**
     * @brief Time when received PFC priority5 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_TIME_PFC5                      = 34,

    /**
     * @brief Time when received PFC priority6 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_TIME_PFC6                      = 35,

    /**
     * @brief Time when received PFC priority7 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_TIME_PFC7                      = 36,

    /**
     * @brief Number of frames received with any error CRC, length, alignemnt, run, etc; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_ERR_ANY                 = 37,

    /**
     * @brief Number of frames received with a CRC error; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_ERR_CRC                 = 38,

    /**
     * @brief Number of frames received with length error; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_ERR_LEN                 = 39,

    /**
     * @brief Number of frames received that were shorter than the minimum frame size and had no CRC error; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_ERR_RUNT                = 40,

    /**
     * @brief Number of frames received that were longer than the maximum frame size and had no CRC error; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_ERR_OVER                = 41,

    /**
     * @brief Number of frames received that had stomped CRC; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_ERR_STOMPED             = 42,

    /**
     * @brief Number of frames received with a framing error; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_ERR_FRAMING             = 43,

    /**
     * @brief Number of cycles when the MAC receieved more runt/fragments in a cycle than the MAC could process; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_CYCLES_ERR_OVERLOAD            = 44,

    /**
     * @brief Number of cycles when a MAC receive FIFO overflow error was detected; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_CYCLES_ERR_MAC_FIFO_OVERFLOW   = 45,

    /**
     * @brief Number of frames received with Pause/Priority FC error; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_FRAMES_ERR_FC                  = 46,

    /**
     * @brief Number of bytes received in all frames; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_BYTES_ALL                      = 47,

    /**
     * @brief Number of bytes received in frames that had no error; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_BYTES_OK                       = 48,

    /**
     * @brief PCS Receive BER BAD Count; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_PCS_BER_COUNT                  = 49,

    /**
     * @brief PCS receive block error count; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_PCS_BLOCK_ERR_COUNT            = 50,

    /**
     * @brief PCS receive test error count; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_PCS_TEST_ERR_COUNT             = 51,

    /**
     * @brief KR/KP/FC FEC receive corrected codeword count; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_KRPFEC_CORRECTED_CW_COUNT      = 52,

    /**
     * @brief KR/KP/FC FEC receive uncorrected codeword count; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_KRPFEC_UNCORRECTED_CW_COUNT    = 53,

    /**
     * @brief KR/KP/FC FEC receive symbol errors; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_KRPFEC_CW_SYMBOL_ERR           = 54,

    /**
     * @brief Sync header error count; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_PCS_SYNC_HEADER_ERR_COUNT      = 55,

    /**
     * @brief PCS BIP error count; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_PCS_BIP_ERR_COUNT              = 56,

    /**
     * @brief Alignment lane map error count; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_PCS_ALIGN_MAP_ERR_COUNT        = 57,

    /**
     * @brief Alignment skew error count; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_PCS_ALIGN_SKEW_ERR_COUNT       = 58,

    /**
     * @brief FEC codeword error count; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_PCS_FEC_CODEWORD_ERR_COUNT     = 59,

    /**
     * @brief Alignment marker error count; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_PCS_ALIGNMENT_MARKER_ERR_COUNT = 60,

    /**
     * @brief KR/KP/FC FEC receive 0to1 error count; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_KRPFEC_CW_BIT_0TO1_COUNT       = 61,

    /**
     * @brief KR/KP/FC FEC receive 0to1 error count; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_KRPFEC_CW_BIT_1TO0_COUNT       = 62,

    /**
     * @brief Number of frames transmitted; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_ALL                     = 63,

    /**
     * @brief Number of frames transmitted without any error; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_OK                      = 64,

    /**
     * @brief Number of tx frames dropped; valid for CPU port only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_DROP                    = 65,

    /**
     * @brief Number of frames transmitted with unicast address; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_UNICAST                 = 66,

    /**
     * @brief Number of frames transmitted with multicast address; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_MULTICAST               = 67,

    /**
     * @brief Number of frames transmitted with broadcast address; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_BROADCAST               = 68,

    /**
     * @brief Number of frames transmitted with Pause type; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_PAUSE                   = 69,

    /**
     * @brief Number of frames transmitted with Priority Flow Control type; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_PFC                     = 70,

    /**
     * @brief Number of frames transmitted that were VLAN tagged and that had no CRC error; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_VLAN                    = 71,

    /**
     * @brief Number of frames transmitted that were shorter than 64 bytes; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_LEN_LT_64               = 72,

    /**
     * @brief Number of frames transmitted that were 64 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_LEN_64                  = 73,

    /**
     * @brief Number of frames transmitted that were 65 to 127 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_LEN_65_127              = 74,

    /**
     * @brief Number of frames transmitted that were 128 to 255 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_LEN_128_255             = 75,

    /**
     * @brief Number of frames transmitted that were 256 to 511 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_LEN_256_511             = 76,

    /**
     * @brief Number of frames transmitted that were 512 to 1023 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_LEN_512_1023            = 77,

    /**
     * @brief Number of frames transmitted that were 1024 to 1518 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_LEN_1024_1518           = 78,

    /**
     * @brief Number of frames transmitted that were 1519 to 2047 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_LEN_1519_2047           = 79,

    /**
     * @brief Number of frames transmitted that were 2048 to 4095 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_LEN_2048_4095           = 80,

    /**
     * @brief Number of frames transmitted that were 4096 to 8191 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_LEN_4096_8191           = 81,

    /**
     * @brief Number of frames transmitted that were 8192 to 9215 bytes long; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_LEN_8192_9215           = 82,

    /**
     * @brief Number of frames transmitted that were longer than 9215 bytes; valid for ETH and CPU ports
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_LEN_GE_9216             = 83,

    /**
     * @brief Number of PFC frames transmitted with priority0 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_PFC0                    = 84,

    /**
     * @brief Number of PFC frames transmitted with priority1 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_PFC1                    = 85,

    /**
     * @brief Number of PFC frames transmitted with priority2 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_PFC2                    = 86,

    /**
     * @brief Number of PFC frames transmitted with priority3 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_PFC3                    = 87,

    /**
     * @brief Number of PFC frames transmitted with priority4 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_PFC4                    = 88,

    /**
     * @brief Number of PFC frames transmitted with priority5 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_PFC5                    = 89,

    /**
     * @brief Number of PFC frames transmitted with priority6 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_PFC6                    = 90,

    /**
     * @brief Number of PFC frames transmitted with priority7 XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_PFC7                    = 91,

    /**
     * @brief Time when PFC transmit priority0 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_TIME_PFC0                      = 92,

    /**
     * @brief Time when PFC transmit priority1 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_TIME_PFC1                      = 93,

    /**
     * @brief Time when PFC transmit priority2 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_TIME_PFC2                      = 94,

    /**
     * @brief Time when PFC transmit priority3 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_TIME_PFC3                      = 95,

    /**
     * @brief Time when PFC transmit priority4 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_TIME_PFC4                      = 96,

    /**
     * @brief Time when PFC transmit priority5 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_TIME_PFC5                      = 97,

    /**
     * @brief Time when PFC transmit priority6 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_TIME_PFC6                      = 98,

    /**
     * @brief Time when PFC transmit priority7 was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_TIME_PFC7                      = 99,

    /**
     * @brief Number of frames transmitted with an error CRC; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_ERR_ANY                 = 100,

    /**
     * @brief Number of frames transmitted that had intentially bad CRC; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_ERR_CRC                 = 101,

    /**
     * @brief Number of cycles when a MAC transmit bus protocol error was detected; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_CYCLES_ERR_MAC_PROTOCOL        = 102,

    /**
     * @brief Number of cycles when a MAC transmit FIFO overflow error was detected; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_CYCLES_ERR_MAC_FIFO_OVERFLOW   = 103,

    /**
     * @brief Number of cycles when a MAC transmit FIFO underflow error was detected; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_CYCLES_ERR_MAC_FIFO_UNDERFLOW  = 104,

    /**
     * @brief Number of frames transmitted that were longer than the maximum frame size; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_FRAMES_ERR_OVER                = 105,

    /**
     * @brief Number of bytes transmitted in frames; valid for ETH and CPU ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_BYTES_ALL                      = 106,

    /**
     * @brief Number of bytes transmitted in frames that had no error; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_BYTES_OK                       = 107,

    /**
     * @brief Number of packets dropped due to green AQM drops due to either WRED Drops or Congestion Unresponsive color-based drops for Green packets; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_AQM_GREEN_PACKET_DROP_COUNT       = 108,

    /**
     * @brief Number of packets dropped due to  green AQM drops due to either WRED Drops or Congestion Unresponsive color-based drops for Yellow packets; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_AQM_YELLOW_PACKET_DROP_COUNT      = 109,

    /**
     * @brief Number of packets dropped due to green AQM drops due to either WRED Drops or Congestion Unresponsive color-based drops for Red packets; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_AQM_RED_PACKET_DROP_COUNT         = 110,

    /**
     * @brief Number of legal length frames which had bad CRC. Short frames with bad CRC will not be counted. Long frames with bad CRC will be counted as jabbers, this excludes frames with symbol errors; valid for AUX ports only
     *
     * type = uint64_t
     * device restrictions = supported on IFCS_DEVICE_TERALYNX5
     */
    IFCS_DEVPORT_STATS_ID_RX_JABBER                         = 111,

    /**
     * @brief Time when received Pause was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_RX_TIME_PAUSE                     = 112,

    /**
     * @brief Time when received Pause was XOff; valid for ETH ports only
     *
     * type = uint64_t
     */
    IFCS_DEVPORT_STATS_ID_TX_TIME_PAUSE                     = 113,

    /**
     * @brief MAX Stats id
     */
    IFCS_DEVPORT_STATS_ID_MAX_COUNT                         = 114,

    /**
     * @brief All Stats id
     */
    IFCS_DEVPORT_STATS_ID_ALL                               = 115,
} ifcs_devport_stats_id_t;


/**
 * @brief Create a devport
 *
 * Create a devport
 * Refer to ifcs_devport_attr_id_t for attributes applicable.
 *
 * @param [in] node_id     - Node identifier
 * @param [in] devport     - devport
 * @param [in] attr_count  - Number of attributes
 * @param [in] attr_list_p - Attribute list
 * @return ifcs_status_t
 */
ifcs_status_t
ifcs_devport_create(ifcs_node_id_t node_id,
                    ifcs_devport_t devport,
                    uint32_t       attr_count,
                    ifcs_attr_t    *attr_list_p);


/**
 * @brief Delete a devport
 *
 * Delete a devport
 * @param [in] node_id - Node identifier
 * @param [in] devport - devport
 * @return ifcs_status_t
 */
ifcs_status_t
ifcs_devport_delete(ifcs_node_id_t node_id,
                    ifcs_devport_t devport);


/**
 * @brief Set attributes for a given devport
 *
 * Refer to ifcs_devport_attr_id_t for attributes applicable.
 *
 * @param [in] node_id     - Node identifier
 * @param [in] devport     - devport
 * @param [in] attr_count  - Number of attributes
 * @param [in] attr_list_p - Attribute list
 * @return ifcs_status_t
 */
ifcs_status_t
ifcs_devport_attr_set(ifcs_node_id_t node_id,
                      ifcs_devport_t devport,
                      uint32_t       attr_count,
                      ifcs_attr_t    *attr_list_p);

/**
 * @brief Get attributes for a given devport
 *
 * Refer to ifcs_devport_attr_id_t for attributes applicable.
 *
 * @param [in]     node_id             - Node identifier
 * @param [in]     devport             - devport
 * @param [in]     attr_count          - Number of attributes
 * @param [in,out] attr_list_p         - Attribute list
 * @param [out]    actual_attr_count_p - Actual attributes count
 * @return ifcs_status_t
 */
ifcs_status_t
ifcs_devport_attr_get(ifcs_node_id_t node_id,
                      ifcs_devport_t devport,
                      uint32_t       attr_count,
                      ifcs_attr_t    *attr_list_p,
                      uint32_t       *actual_attr_count_p);


/**
 * @brief User defined callback to be called during ifcs_devport_get_all
 *
 * This callback function is called for every devport entry in the
 * device.
 *
 * @param [in]     node_id         - Node identifier
 * @param [in]     devport         - devport
 * @param [in]     attr_count      - attribute count
 * @param [in]     attr_list_p     - list of attributes
 * @param [in,out] user_data_p     - User provided data
 */
typedef void
(ifcs_devport_user_cb_t) (ifcs_node_id_t node_id,
                          ifcs_devport_t devport,
                          uint32_t       attr_count,
                          ifcs_attr_t    *attr_list_p,
                          void           *user_data_p);

/**
 * @brief Get all the devport API objects
 *
 * @param [in]  node_id            - Node identifier
 * @param [in]  filter_attr_count  - Number of attributes
 * @param [in]  filter_attr_list_p - List of attributes that matches the object
 * @param [in]  user_cb_p          - Callback function to be called for each stored devport if NULL then gets the count only
 * @param [in]  user_data_p        - Pointer  to user data
 * @param [out] count_p            - Number of objects
 * @return ifcs_status_t
 */
ifcs_status_t
ifcs_devport_get_all(ifcs_node_id_t         node_id,
                     uint32_t               filter_attr_count,
                     ifcs_attr_t            *filter_attr_list_p,
                     ifcs_devport_user_cb_t *user_cb_p,
                     void                   *user_data_p,
                     uint32_t               *count_p);

/**
 * @brief Get Stats for a given devport
 *
 * @param [in]  node_id                     - Node identifier
 * @param [in]  devport                     - devport
 * @param [in]  number_of_counters          - Number of counters to get
 * @param [in]  counter_ids_p               - Counter ids
 * @param [out] counters_p                  - Counter values
 * @param [out] actual_number_of_counters_p - Actual number of counters filled
 * @return ifcs_status_t
 */
ifcs_status_t
ifcs_devport_stats_get(ifcs_node_id_t          node_id,
                       ifcs_devport_t          devport,
                       uint32_t                number_of_counters,
                       ifcs_devport_stats_id_t *counter_ids_p,
                       uint64_t                *counters_p,
                       uint32_t                *actual_number_of_counters_p);

/**
 * @brief Get Detailed Stats for a given devport
 *
 * @param [in]  node_id            - Node identifier
 * @param [in]  devport            - devport
 * @param [in]  number_of_counters - Number of counters to get
 * @param [in]  counter_ids_p      - Counter ids
 * @param [out] counters_p         - Counter values
 * @return ifcs_status_t
 */
ifcs_status_t
ifcs_devport_stats_detail_get(ifcs_node_id_t          node_id,
                              ifcs_devport_t          devport,
                              uint32_t                number_of_counters,
                              ifcs_devport_stats_id_t *counter_ids_p,
                              ifcs_counter_t          *counters_p);

/**
 * @brief Clear Stats for a given devport
 *
 * @param [in] node_id            - Node identifier
 * @param [in] devport            - devport
 * @param [in] number_of_counters - Number of counters to get
 * @param [in] counter_ids_p      - Counter ids
 * @return ifcs_status_t
 */
ifcs_status_t
ifcs_devport_stats_clear(ifcs_node_id_t          node_id,
                         ifcs_devport_t          devport,
                         uint32_t                number_of_counters,
                         ifcs_devport_stats_id_t *counter_ids_p);

/**
 * @brief User defined callback to be called during ifcs_devport_stats_clear_all
 *
 * This callback function is called to clear stats of devport entry in the
 * device matching the filter.
 *
 * @param [in]  node_id            - Node identifier
 * @param [in]  devport            - devport
 * @param [in]  number_of_counters - Number of counters to clear
 * @param [in]  counter_ids_p      - Counter ids
 * @param [out] counters_p         - Counter values
 * @param [in,out] user_data_p     - User provided data
 */
typedef void
(ifcs_devport_clear_stats_user_cb_t) (ifcs_node_id_t          node_id,
                                      ifcs_devport_t          devport,
                                      uint32_t                number_of_counters,
                                      ifcs_devport_stats_id_t *counter_ids_p,
                                      uint64_t                *counters_p,
                                      void                    *user_data_p);

/**
 * @brief Clear all the stats of all the objects of devport API class
 * User has multiple options:
 * 1. User can filter the objects on which stats has to be cleared by passing partial keys for API classes with multi-key,
 *    user can also filter based on attributes being set to certain values.
 * 2. User can get the number of objects on which the stats were cleared by passing the *count_p.
 * 3. User can get notified about all the objects on which stats were cleared by passing a valid
 *    callback function.
 *
 * @param [in]  node_id            - Node identifier
 * @param [in]  filter_attr_count  - Number of attributes
 * @param [in]  filter_attr_list_p - List of attributes that matches the object
 * @param [in]  user_cb_p          - Callback function to be called for each stored devport stats if NULL then gets the count only
 * @param [in]  user_data_p        - Pointer  to user data
 * @param [out] count_p            - Number of objects matching the filter
 * @return ifcs_status_t
 */
ifcs_status_t
ifcs_devport_stats_clear_all(ifcs_node_id_t                     node_id,
                             uint32_t                           filter_attr_count,
                             ifcs_attr_t                        *filter_attr_list_p,
                             ifcs_devport_clear_stats_user_cb_t *user_cb_p,
                             void                               *user_data_p,
                             uint32_t                           *count_p);

#endif /* __IFCS_DEVPORT_H__ */
