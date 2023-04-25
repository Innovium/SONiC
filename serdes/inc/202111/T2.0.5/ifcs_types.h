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
 * @file  ifcs_types.h
 * @brief IFCS enums, defines and data structures
 */

#ifndef __IFCS_TYPES_H__
#define __IFCS_TYPES_H__

#include <stdint.h>
#include <sys/types.h>
#include <stdlib.h>
#include "ifcs_handle.h"
#include "ifcs_status.h"
/**
 * @brief class for stats_detail_get
 */
typedef enum ifcs_stats_class_e {

    IFCS_STATS_CLASS_REGULAR = 0, ///< REGULAR
    IFCS_STATS_CLASS_DROP    = 1, ///< DROP
    IFCS_STATS_CLASS_ERROR   = 2, ///< ERROR
} ifcs_stats_class_t;

/**
 * @brief stat direction for stats_detail_get
 */
typedef enum ifcs_stats_direction_e {

    IFCS_STATS_DIRECTION_NONE = 0, ///< NONE
    IFCS_STATS_DIRECTION_RX   = 1, ///< RX
    IFCS_STATS_DIRECTION_TX   = 2, ///< TX
} ifcs_stats_direction_t;

/**
 * @brief port speed
 */
typedef enum ifcs_devport_speed_e {

    IFCS_DEVPORT_SPEED_INVALID  = 0,  ///< INVALID
    IFCS_DEVPORT_SPEED_10G      = 1,  ///< 10G
    IFCS_DEVPORT_SPEED_25G      = 2,  ///< 25G
    IFCS_DEVPORT_SPEED_40G      = 3,  ///< 40G
    IFCS_DEVPORT_SPEED_50G      = 4,  ///< 50G
    IFCS_DEVPORT_SPEED_100G     = 5,  ///< 100G
    IFCS_DEVPORT_SPEED_200G     = 6,  ///< 200G
    IFCS_DEVPORT_SPEED_400G     = 7,  ///< 400G
    IFCS_DEVPORT_SPEED_AUX      = 8,  ///< AUX
    IFCS_DEVPORT_SPEED_INTERNAL = 9,  ///< INTERNAL
    IFCS_DEVPORT_SPEED_1G       = 10, ///< 1G
    IFCS_DEVPORT_SPEED_MAX      = 11, ///< MAX
} ifcs_devport_speed_t;

/**
 * @brief API paramter flags
 */
typedef enum ifcs_api_param_flags_e {

    IFCS_API_PARAM_FLAGS_STOP_ON_ERROR     = 0x1, ///< Stop processing the API when an error is encountered
    IFCS_API_PARAM_FLAGS_CONTINUE_ON_ERROR = 0x2, ///< Ignore the error and continue with the API
    IFCS_API_PARAM_FLAGS_START_INDEX       = 0x4, ///< Start the bulk operation from the given index
} ifcs_api_param_flags_t;

/**
 * @brief IFCS Initialization options
 */
typedef enum ifcs_boot_e {

    IFCS_BOOT_COLD = 0, ///< Initialize IFCS in Cold Mode
    IFCS_BOOT_WARM = 1, ///< Initialize IFCS in Warbmoot Mode
} ifcs_boot_t;

/**
 * @brief IFCS Shutdown options
 */
typedef enum ifcs_shutdown_type_e {

    IFCS_SHUTDOWN_TYPE_COLD           = 0, ///< Shutdown IFCS in Cold Mode
    IFCS_SHUTDOWN_TYPE_WARM           = 1, ///< Shutdown IFCS in Warbmoot Mode
    IFCS_SHUTDOWN_TYPE_WARM_NOMEM_REL = 2, ///< Shutdown IFCS in Warbmoot Mode, don't release memory
    IFCS_SHUTDOWN_TYPE_WARM_SNAPSHOT  = 3, ///< Snapshot IFCS, for test execution only
} ifcs_shutdown_type_t;

/**
 * @brief IFCS bool type
 */
typedef enum ifcs_bool_e {

    IFCS_BOOL_FALSE = 0, ///< FALSE
    IFCS_BOOL_TRUE  = 1, ///< TRUE
} ifcs_bool_t;

/**
 * @brief IP address family types
 */
typedef enum ifcs_ip_addr_family_e {

    IFCS_IP_ADDR_FAMILY_IPV4 = 0, ///< IPv4 family
    IFCS_IP_ADDR_FAMILY_IPV6 = 1, ///< IPv6 family
} ifcs_ip_addr_family_t;

/**
 * @brief API class for usage object (used in overloaded usage_detail_get APIs)
 */
typedef enum ifcs_usage_obj_api_class_id_e {

    IFCS_USAGE_OBJ_API_CLASS_ID_INTF    = 0, ///< INTF
    IFCS_USAGE_OBJ_API_CLASS_ID_NEXTHOP = 1, ///< NEXTHOP
    IFCS_USAGE_OBJ_API_CLASS_ID_L3VNI   = 2, ///< L3VNI
    IFCS_USAGE_OBJ_API_CLASS_ID_MAX     = 3, ///< MAX
} ifcs_usage_obj_api_class_id_t;

/**
 * @brief Usage objects for intf usage detail API
 */
typedef enum ifcs_usage_obj_intf_e {

    IFCS_USAGE_OBJ_INTF_DEFAULT    = 0, ///< Interface count
    IFCS_USAGE_OBJ_INTF_NON_TUNNEL = 1, ///< Non-tunnel interface count
    IFCS_USAGE_OBJ_INTF_TUNNEL_L2  = 2, ///< L2 tunnel interface count
    IFCS_USAGE_OBJ_INTF_TUNNEL_L3  = 3, ///< L3 tunnel interface count
    IFCS_USAGE_OBJ_INTF_SIP        = 4, ///< Interface Source IP count
    IFCS_USAGE_OBJ_INTF_DIP        = 5, ///< Interface Destination IP count
} ifcs_usage_obj_intf_t;

/**
 * @brief Usage objects for nexthop usage detail API
 */
typedef enum ifcs_usage_obj_nexthop_e {

    IFCS_USAGE_OBJ_NEXTHOP_INTF_TYPE_L3PORT             = 0,  ///< Nexthop L3 port count
    IFCS_USAGE_OBJ_NEXTHOP_INTF_TYPE_SVI                = 1,  ///< Nexthop SVI count
    IFCS_USAGE_OBJ_NEXTHOP_INTF_TYPE_L3_PORT_CVID       = 2,  ///< Nexthop L3 sub-intf port count
    IFCS_USAGE_OBJ_NEXTHOP_INTF_TYPE_IP_IN_IPV4         = 3,  ///< Nexthop IP_IN_IPV4 count
    IFCS_USAGE_OBJ_NEXTHOP_INTF_TYPE_IP_IN_IPV6         = 4,  ///< Nexthop IP_IN_IPV6 count
    IFCS_USAGE_OBJ_NEXTHOP_INTF_TYPE_IP_IN_IPV4_GRE     = 5,  ///< Nexthop IP_IN_IPV4_GRE count
    IFCS_USAGE_OBJ_NEXTHOP_INTF_TYPE_IP_IN_IPV6_GRE     = 6,  ///< Nexthop IP_IN_IPV6_GRE count
    IFCS_USAGE_OBJ_NEXTHOP_INTF_TYPE_IP_IN_IPV4_GRE_KEY = 7,  ///< Nexthop IP_IN_IPV4_GRE_KEY count
    IFCS_USAGE_OBJ_NEXTHOP_INTF_TYPE_IP_IN_IPV6_GRE_KEY = 8,  ///< Nexthop IP_IN_IPV6_GRE_KEY count
    IFCS_USAGE_OBJ_NEXTHOP_INTF_TYPE_L2_IN_IPV4_VXLAN   = 9,  ///< Nexthop L2_IN_IPV4_VXLAN count
    IFCS_USAGE_OBJ_NEXTHOP_INTF_TYPE_L2_IN_IPV6_VXLAN   = 10, ///< Nexthop L2_IN_IPV6_VXLAN count
    IFCS_USAGE_OBJ_NEXTHOP_INTF_TYPE_MAX                = 11, ///< Nexthop MAX count
    IFCS_USAGE_OBJ_NEXTHOP_INTF_NON_TUNNEL              = 12, ///< Nexthop Non-Tunnel count
    IFCS_USAGE_OBJ_NEXTHOP_INTF_TUNNEL                  = 13, ///< Nexthop Tunnel count
} ifcs_usage_obj_nexthop_t;

/**
 * @brief Usage objects for l3vni usage detail API
 */
typedef enum ifcs_usage_obj_l3vni_e {

    IFCS_USAGE_OBJ_L3VNI_DEFAULT = 0, ///< Usage including reserved L3VNIs
} ifcs_usage_obj_l3vni_t;

/**
 * @brief Enum defining QOS map types.
 */
typedef enum ifcs_qos_map_type_e {

    IFCS_QOS_MAP_TYPE_DOT1P_CFI_TO_TC_DP = 0, ///< QOS map DOT1P_CFI to Traffic-class/Drop-precedence
    IFCS_QOS_MAP_TYPE_DSCP_TO_TC_DP      = 1, ///< QOS map DSCP to Traffic-class/Drop-precedence
    IFCS_QOS_MAP_TYPE_EXP_TO_TC_DP       = 2, ///< QOS map EXP to Traffic-class/Drop-precedence
    IFCS_QOS_MAP_TYPE_TC_DP_TO_DOT1P_CFI = 3, ///< QOS map Traffic-class/Drop-precedence to DOT1P_CFI
    IFCS_QOS_MAP_TYPE_TC_DP_TO_DSCP      = 4, ///< QOS map Traffic-class/Drop-precedence to DSCP
    IFCS_QOS_MAP_TYPE_TC_DP_TO_EXP       = 5, ///< QOS map Traffic-class/Drop-precedence to EXP
    IFCS_QOS_MAP_TYPE_MAX_COUNT          = 6, ///< MAX_COUNT
} ifcs_qos_map_type_t;

/**
 * @brief Forwarding action
 */
typedef enum ifcs_fwd_action_e {

    IFCS_FWD_ACTION_FORWARD = 0, ///< FORWARD
    IFCS_FWD_ACTION_DROP    = 1, ///< DROP
} ifcs_fwd_action_t;

/**
 * @brief Enable/Disable Copy To CPU for a given API object
 */
typedef enum ifcs_copy_to_cpu_e {

    IFCS_COPY_TO_CPU_DISABLE = 0, ///< Disable Copy to CPU
    IFCS_COPY_TO_CPU_ENABLE  = 1, ///< Enable Copy to CPU
} ifcs_copy_to_cpu_t;

/**
 * @brief ACL action enable/disable
 */
typedef enum ifcs_acl_action_e {

    IFCS_ACL_ACTION_DISABLE = 0, ///< DISABLE
    IFCS_ACL_ACTION_ENABLE  = 1, ///< ENABLE
} ifcs_acl_action_t;

/**
 * @brief ACL IPT action clone/override-clone/no-op
 */
typedef enum ifcs_acl_ipt_operation_e {

    IFCS_ACL_IPT_OPERATION_CREATE_IPT_COPY   = 0, ///< Triggers the copy of an IPT copy of the packet - valid only when telemetry instance trigger type is IFCS_TELEMETRY_IPT_PACKET_TRIGGER_TYPE_USER_DEFINE
    IFCS_ACL_IPT_OPERATION_OVERRIDE_IPT_COPY = 1, ///< Do not create an IPT for this packet - valid only when telemetry instance trigger type is IFCS_TELEMETRY_IPT_PACKET_TRIGGER_TYPE_SAMPLING
    IFCS_ACL_IPT_OPERATION_NOOP              = 2, ///< No Operation
} ifcs_acl_ipt_operation_t;

/**
 * @brief Traffic Monitoring actions for a given API object
 */
typedef enum ifcs_traffic_monitor_action_e {

    IFCS_TRAFFIC_MONITOR_ACTION_ENABLE  = 0, ///< Enable Traffic Monitoring
    IFCS_TRAFFIC_MONITOR_ACTION_DISABLE = 1, ///< Disable Traffic Monitoring
} ifcs_traffic_monitor_action_t;

/**
 * @brief Traffic Monitoring container - a Traffic Monitoring container contains a Traffic Monitoring session
 */
typedef enum ifcs_traffic_monitor_container_e {

    IFCS_TRAFFIC_MONITOR_CONTAINER_0 = 0, ///< Use container 0 for Traffic Monitoring
    IFCS_TRAFFIC_MONITOR_CONTAINER_1 = 1, ///< Use container 1 for Traffic Monitoring
} ifcs_traffic_monitor_container_t;

/**
 * @brief Stats mode of operation
 */
typedef enum ifcs_stats_mode_e {

    IFCS_STATS_MODE_PKT_BYTE_WIDE       = 0, ///< PKT_BYTE_WIDE
    IFCS_STATS_MODE_PKT_BYTE_EXTRA_WIDE = 1, ///< PKT_BYTE_EXTRA_WIDE
    IFCS_STATS_MODE_PKT_ONLY_WIDE       = 2, ///< PKT_ONLY_WIDE
    IFCS_STATS_MODE_PKT_ONLY_EXTRA_WIDE = 3, ///< PKT_ONLY_EXTRA_WIDE
    IFCS_STATS_MODE_MAX                 = 4, ///< MAX
} ifcs_stats_mode_t;

/**
 * @brief Stats counting mode
 */
typedef enum ifcs_l2vni_stats_count_mode_e {

    IFCS_L2VNI_STATS_COUNT_MODE_DISABLE  = 0, ///< DISABLE
    IFCS_L2VNI_STATS_COUNT_MODE_ALL      = 1, ///< ALL
    IFCS_L2VNI_STATS_COUNT_MODE_UC_MC_BC = 2, ///< UC_MC_BC
    IFCS_L2VNI_STATS_COUNT_MODE_UC_ONLY  = 3, ///< UC_ONLY
    IFCS_L2VNI_STATS_COUNT_MODE_UC_NONUC = 4, ///< UC_NONUC
    IFCS_L2VNI_STATS_COUNT_MODE_MAX      = 5, ///< MAX
} ifcs_l2vni_stats_count_mode_t;

/**
 * @brief Stats counting mode
 */
typedef enum ifcs_l3intf_stats_count_mode_e {

    IFCS_L3INTF_STATS_COUNT_MODE_DISABLE       = 0, ///< DISABLE
    IFCS_L3INTF_STATS_COUNT_MODE_ALL           = 1, ///< ALL
    IFCS_L3INTF_STATS_COUNT_MODE_UC_MC_BC      = 2, ///< UC_MC_BC
    IFCS_L3INTF_STATS_COUNT_MODE_UC_ONLY       = 3, ///< UC_ONLY
    IFCS_L3INTF_STATS_COUNT_MODE_IPV4_IPV6_ANY = 4, ///< IPV4_IPV6_ANY
    IFCS_L3INTF_STATS_COUNT_MODE_FLEX_2C       = 5, ///< FLEX_2C
    IFCS_L3INTF_STATS_COUNT_MODE_MAX           = 6, ///< MAX
} ifcs_l3intf_stats_count_mode_t;

/**
 * @brief L3 Tunnel interface stats counting mode
 */
typedef enum ifcs_l3tunnel_intf_stats_count_mode_e {

    IFCS_L3TUNNEL_INTF_STATS_COUNT_MODE_DISABLE = 0, ///< DISABLE
    IFCS_L3TUNNEL_INTF_STATS_COUNT_MODE_ALL     = 1, ///< ALL
    IFCS_L3TUNNEL_INTF_STATS_COUNT_MODE_MAX     = 2, ///< MAX
} ifcs_l3tunnel_intf_stats_count_mode_t;

/**
 * @brief L3 Tunnel interface stats profile to specify drop counters
 */
typedef enum ifcs_l3tunnel_intf_stats_drop_profile_e {

    IFCS_L3TUNNEL_INTF_STATS_DROP_PROFILE_FWD_ONLY    = 0, ///< FWD_ONLY
    IFCS_L3TUNNEL_INTF_STATS_DROP_PROFILE_FWD_DROP_1C = 1, ///< FWD_DROP_1C
    IFCS_L3TUNNEL_INTF_STATS_DROP_PROFILE_MAX         = 2, ///< MAX
} ifcs_l3tunnel_intf_stats_drop_profile_t;

/**
 * @brief Type of ring
 */
typedef enum ifcs_ring_type_e {

    IFCS_RING_TYPE_RX = 0, ///< RX ring
    IFCS_RING_TYPE_TX = 1, ///< TX ring
} ifcs_ring_type_t;

/**
 * @brief Type of ring
 */
typedef enum ifcs_ring_mgr_type_e {

    IFCS_RING_MGR_TYPE_USER   = 0, ///< Ring managed in user space
    IFCS_RING_MGR_TYPE_KERNEL = 1, ///< Ring managed in kernel space
} ifcs_ring_mgr_type_t;

/**
 * @brief Metering mode
 */
typedef enum ifcs_meter_mode_e {

    IFCS_METER_MODE_TOKEN_BUCKET = 0, ///< TOKEN_BUCKET
} ifcs_meter_mode_t;

/**
 * @brief Flex op command
 */
typedef enum ifcs_flex_op_cmd_e {

    IFCS_FLEX_OP_CMD_NOOP           = 0, ///< No count action
    IFCS_FLEX_OP_CMD_COUNT          = 1, ///< Enable counting
    IFCS_FLEX_OP_CMD_COUNT_OVERRIDE = 2, ///< Count cancel
} ifcs_flex_op_cmd_t;

/**
 * @brief Offset for L2VNI fine grained flex stats (UC, MC, BC)
 */
typedef enum ifcs_l2vni_flex_offset_e {

    IFCS_L2VNI_FLEX_OFFSET_UC = 0, ///< UC
    IFCS_L2VNI_FLEX_OFFSET_MC = 1, ///< MC
    IFCS_L2VNI_FLEX_OFFSET_BC = 2, ///< BC
} ifcs_l2vni_flex_offset_t;

/**
 * @brief Offset for L2VNI fine grained flex stats (UC, NONUC)
 */
typedef enum ifcs_l2vni_stats_mode_uc_nonuc_flex_offset_e {

    IFCS_L2VNI_STATS_MODE_UC_NONUC_FLEX_OFFSET_UC    = 0, ///< UC
    IFCS_L2VNI_STATS_MODE_UC_NONUC_FLEX_OFFSET_NONUC = 1, ///< NONUC
} ifcs_l2vni_stats_mode_uc_nonuc_flex_offset_t;

/**
 * @brief Offset for L3INTF fine grained flex stats (Offset0, Offset1)
 */
typedef enum ifcs_l3intf_stats_mode_flex_2c_e {

    IFCS_L3INTF_STATS_MODE_FLEX_2C_OFFSET0 = 0, ///< OFFSET0
    IFCS_L3INTF_STATS_MODE_FLEX_2C_OFFSET1 = 1, ///< OFFSET1
} ifcs_l3intf_stats_mode_flex_2c_t;

/**
 * @brief DTL factor - 1/16, 1/8, 1/4, 1/2, 1, 2, 4, 8
 */
typedef enum ifcs_dtl_factor_e {

    IFCS_DTL_FACTOR_INVALID       = 0, ///< DTL factor is invalid
    IFCS_DTL_FACTOR_ONE_SIXTEENTH = 1, ///< ONE_SIXTEENTH
    IFCS_DTL_FACTOR_ONE_EIGHTH    = 2, ///< ONE_EIGHTH
    IFCS_DTL_FACTOR_ONE_FOURTH    = 3, ///< ONE_FOURTH
    IFCS_DTL_FACTOR_ONE_HALF      = 4, ///< ONE_HALF
    IFCS_DTL_FACTOR_ONE           = 5, ///< ONE
    IFCS_DTL_FACTOR_TWO           = 6, ///< TWO
    IFCS_DTL_FACTOR_FOUR          = 7, ///< FOUR
    IFCS_DTL_FACTOR_EIGHT         = 8, ///< EIGHT
} ifcs_dtl_factor_t;

/**
 * @brief IFCS VLAN Map Tag Type
 */
typedef enum ifcs_vlan_map_tag_type_e {

    IFCS_VLAN_MAP_TAG_TYPE_CTAG = 0, ///< CTAG
    IFCS_VLAN_MAP_TAG_TYPE_STAG = 1, ///< STAG
} ifcs_vlan_map_tag_type_t;

/**
 * @brief dot1p and cfi derivation type
 */
typedef enum ifcs_dot1p_cfi_source_type_e {

    IFCS_DOT1P_CFI_SOURCE_TYPE_USE_VALUE = 0, ///< use specified value
    IFCS_DOT1P_CFI_SOURCE_TYPE_USE_MAP   = 1, ///< derive from TC and PLP
} ifcs_dot1p_cfi_source_type_t;

/**
 * @brief VLAN tag operations when VLAN tag is detected
 */
typedef enum ifcs_tag_action_if_tag_not_detected_cmd_e {

    IFCS_TAG_ACTION_IF_TAG_NOT_DETECTED_CMD_NOOP = 0, ///< NOOP
    IFCS_TAG_ACTION_IF_TAG_NOT_DETECTED_CMD_ADD  = 1, ///< ADD
} ifcs_tag_action_if_tag_not_detected_cmd_t;

/**
 * @brief VLAN tag operations when VLAN tag is detected
 */
typedef enum ifcs_tag_action_if_tag_detected_cmd_e {

    IFCS_TAG_ACTION_IF_TAG_DETECTED_CMD_NOOP    = 0, ///< NOOP
    IFCS_TAG_ACTION_IF_TAG_DETECTED_CMD_DELETE  = 1, ///< DELETE
    IFCS_TAG_ACTION_IF_TAG_DETECTED_CMD_REPLACE = 2, ///< REPLACE
} ifcs_tag_action_if_tag_detected_cmd_t;

/**
 * @brief VLAN tag replace operation type
 */
typedef enum ifcs_tag_action_replace_vid_cmd_e {

    IFCS_TAG_ACTION_REPLACE_VID_CMD_NOOP                       = 0, ///< NOOP
    IFCS_TAG_ACTION_REPLACE_VID_CMD_REPLACE                    = 1, ///< REPLACE
    IFCS_TAG_ACTION_REPLACE_VID_CMD_REPLACE_ONLY_IF_PRI_TAGGED = 2, ///< valid only for sysport action
} ifcs_tag_action_replace_vid_cmd_t;

/**
 * @brief VLAN tag dot1p replace operation type
 */
typedef enum ifcs_tag_action_replace_dot1p_cfi_cmd_e {

    IFCS_TAG_ACTION_REPLACE_DOT1P_CFI_CMD_NOOP    = 0, ///< NOOP
    IFCS_TAG_ACTION_REPLACE_DOT1P_CFI_CMD_REPLACE = 1, ///< REPLACE
} ifcs_tag_action_replace_dot1p_cfi_cmd_t;

/**
 * @brief ingress direction single Mapentry to derive L2VNI and vlan tag actions
 */
typedef enum ifcs_ingress_vni_tag_map_key_type_e {

    IFCS_INGRESS_VNI_TAG_MAP_KEY_TYPE_GLOBAL            = 0, ///< GLOBAL
    IFCS_INGRESS_VNI_TAG_MAP_KEY_TYPE_SYSPORT           = 1, ///< SYSPORT
    IFCS_INGRESS_VNI_TAG_MAP_KEY_TYPE_SYSPORT_SVID      = 2, ///< SYSPORT_SVID
    IFCS_INGRESS_VNI_TAG_MAP_KEY_TYPE_SYSPORT_CVID      = 3, ///< SYSPORT_CVID
    IFCS_INGRESS_VNI_TAG_MAP_KEY_TYPE_SYSPORT_SVID_CVID = 4, ///< SYSPORT_SVID_CVID
} ifcs_ingress_vni_tag_map_key_type_t;

/**
 * @brief egress direction  Mapentry key type to derive egress VLAN vid and vlan tag actions
 */
typedef enum ifcs_egress_vlan_tag_map_key_type_e {

    IFCS_EGRESS_VLAN_TAG_MAP_KEY_TYPE_NOOP                    = 0, ///< NOOP
    IFCS_EGRESS_VLAN_TAG_MAP_KEY_TYPE_GLOBAL                  = 1, ///< GLOBAL
    IFCS_EGRESS_VLAN_TAG_MAP_KEY_TYPE_L2VNI                   = 2, ///< L2VNI
    IFCS_EGRESS_VLAN_TAG_MAP_KEY_TYPE_L2VNI_SYSPORT           = 3, ///< L2VNI_SYSPORT
    IFCS_EGRESS_VLAN_TAG_MAP_KEY_TYPE_L2VNI_SYSPORT_CVID      = 4, ///< L2VNI_SYSPORT_CVID
    IFCS_EGRESS_VLAN_TAG_MAP_KEY_TYPE_L2VNI_SYSPORT_SVID      = 5, ///< L2VNI_SYSPORT_SVID
    IFCS_EGRESS_VLAN_TAG_MAP_KEY_TYPE_L2VNI_SYSPORT_SVID_CVID = 6, ///< L2VNI_SYSPORT_SVID_CVID
} ifcs_egress_vlan_tag_map_key_type_t;

/**
 * @brief Attribute data for port link fault status
 */
typedef enum ifcs_devport_fault_status_e {

    IFCS_DEVPORT_FAULT_STATUS_NONE         = 0, ///< NONE
    IFCS_DEVPORT_FAULT_STATUS_LOCAL_FAULT  = 1, ///< LOCAL_FAULT
    IFCS_DEVPORT_FAULT_STATUS_REMOTE_FAULT = 2, ///< REMOTE_FAULT
    IFCS_DEVPORT_FAULT_STATUS_BOTH         = 3, ///< BOTH
} ifcs_devport_fault_status_t;

/**
 * @brief Attribute data for port oper status
 */
typedef enum ifcs_devport_link_status_e {

    IFCS_DEVPORT_LINK_STATUS_DOWN = 0, ///< DOWN
    IFCS_DEVPORT_LINK_STATUS_UP   = 1, ///< UP
} ifcs_devport_link_status_t;

/**
 * @brief Multicast route key type
 */
typedef enum ifcs_mcast_route_key_type_e {

    IFCS_MCAST_ROUTE_KEY_TYPE_IP_SG_L3VNI    = 0, ///< IP_SG_L3VNI
    IFCS_MCAST_ROUTE_KEY_TYPE_IP_STARG_L3VNI = 1, ///< IP_STARG_L3VNI
} ifcs_mcast_route_key_type_t;

/**
 * @brief Incoming L3 Interface or L3 Interface List
 */
typedef enum ifcs_intf_check_type_e {

    IFCS_INTF_CHECK_TYPE_NONE = 0, ///< NONE
    IFCS_INTF_CHECK_TYPE_INTF = 1, ///< INTF
    IFCS_INTF_CHECK_TYPE_LIST = 2, ///< LIST
} ifcs_intf_check_type_t;

/**
 * @brief Fail policy to apply
 */
typedef enum ifcs_intf_check_fail_policy_e {

    IFCS_INTF_CHECK_FAIL_POLICY_FALLBACK_TO_STARG = 0, ///< FALLBACK_TO_STARG
    IFCS_INTF_CHECK_FAIL_POLICY_FALLBACK_TO_L2    = 1, ///< FALLBACK_TO_L2
} ifcs_intf_check_fail_policy_t;

/**
 * @brief Buffer partition type
 */
typedef enum ifcs_buffer_partition_type_e {

    IFCS_BUFFER_PARTITION_TYPE_LOSSY    = 0, ///< Lossy traffic type
    IFCS_BUFFER_PARTITION_TYPE_LOSSLESS = 1, ///< Lossless traffic type
    IFCS_BUFFER_PARTITION_TYPE_HYBRID   = 2, ///< Lossy and lossless traffic type
} ifcs_buffer_partition_type_t;

/**
 * @brief Threshold mode
 */
typedef enum ifcs_threshold_mode_e {

    IFCS_THRESHOLD_MODE_STATIC  = 0, ///< Static threshold mode
    IFCS_THRESHOLD_MODE_DYNAMIC = 1, ///< Dynamic threshold mode
} ifcs_threshold_mode_t;

/**
 * @brief Priority Flow Control(PFC) Code Point(CP)
 */
typedef enum ifcs_pfc_cp_e {

    IFCS_PFC_CP_INVALID = 0, ///< PFC CP is not valid
    IFCS_PFC_CP_0       = 1, ///< PFC CP 0
    IFCS_PFC_CP_1       = 2, ///< PFC CP 1
    IFCS_PFC_CP_2       = 3, ///< PFC CP 2
    IFCS_PFC_CP_3       = 4, ///< PFC CP 3
    IFCS_PFC_CP_4       = 5, ///< PFC CP 4
    IFCS_PFC_CP_5       = 6, ///< PFC CP 5
    IFCS_PFC_CP_6       = 7, ///< PFC CP 6
    IFCS_PFC_CP_7       = 8, ///< PFC CP 7
} ifcs_pfc_cp_t;

/**
 * @brief Match types
 */
typedef enum ifcs_fpf_match_type_e {

    IFCS_FPF_MATCH_TYPE_L2_TYPE          = 0,  ///< L2_TYPE
    IFCS_FPF_MATCH_TYPE_ETHER_TYPE       = 1,  ///< ETHER_TYPE
    IFCS_FPF_MATCH_TYPE_L3_TYPE          = 2,  ///< L3_TYPE
    IFCS_FPF_MATCH_TYPE_IP_PROTO         = 3,  ///< IP_PROTO
    IFCS_FPF_MATCH_TYPE_IP_EXT_HDR1_TYPE = 4,  ///< IP_EXT_HDR1_TYPE
    IFCS_FPF_MATCH_TYPE_IP_EXT_HDR2_TYPE = 5,  ///< IP_EXT_HDR2_TYPE
    IFCS_FPF_MATCH_TYPE_L4_TYPE          = 6,  ///< L4_TYPE
    IFCS_FPF_MATCH_TYPE_L4_SRCPORT       = 7,  ///< L4_SRCPORT
    IFCS_FPF_MATCH_TYPE_L4_DSTPORT       = 8,  ///< L4_DSTPORT
    IFCS_FPF_MATCH_TYPE_SHIM_TYPE        = 9,  ///< SHIM_TYPE
    IFCS_FPF_MATCH_TYPE_SHIM_NEXT_HDR    = 10, ///< SHIM_NEXT_HDR
} ifcs_fpf_match_type_t;

/**
 * @brief FPF Packet field
 */
typedef enum ifcs_fpf_field_e {

    IFCS_FPF_FIELD_1 = 0, ///< 1
    IFCS_FPF_FIELD_2 = 1, ///< 2
} ifcs_fpf_field_t;

/**
 * @brief Packet content to work on
 */
typedef enum ifcs_fpf_base_type_e {

    IFCS_FPF_BASE_TYPE_L2          = 0, ///< L2
    IFCS_FPF_BASE_TYPE_L3          = 1, ///< L3
    IFCS_FPF_BASE_TYPE_L4          = 2, ///< L4
    IFCS_FPF_BASE_TYPE_POST_L4     = 3, ///< POST_L4
    IFCS_FPF_BASE_TYPE_IP_EXT_HDR1 = 4, ///< IP_EXT_HDR1
    IFCS_FPF_BASE_TYPE_IP_EXT_HDR2 = 5, ///< IP_EXT_HDR2
} ifcs_fpf_base_type_t;

/**
 * @brief Enum of devport Auto-Neg base page tech ability
 */
typedef enum ifcs_devport_an_bp_tech_ability_e {

    IFCS_DEVPORT_AN_BP_TECH_ABILITY_NONE             = 0,  ///< NONE
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_1000BASE_KX      = 1,  ///< 1000BASE_KX
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_10GBASE_KX4      = 2,  ///< 10GBASE_KX4
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_10GBASE_KR       = 3,  ///< 10GBASE_KR
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_40GBASE_KR4      = 4,  ///< 40GBASE_KR4
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_40GBASE_CR4      = 5,  ///< 40GBASE_CR4
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_100GBASE_CR10    = 6,  ///< 100GBASE_CR10
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_100GBASE_KP4     = 7,  ///< 100GBASE_KP4
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_100GBASE_KR4     = 8,  ///< 100GBASE_KR4
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_100GBASE_CR4     = 9,  ///< 100GBASE_CR4
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_25GBASE_KR_CR_S  = 10, ///< 25GBASE_KR_CR_S
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_25GBASE_KR_CR    = 11, ///< 25GBASE_KR_CR
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_2_5GBASE_KX      = 12, ///< 2_5GBASE_KX
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_5GBASE_KR        = 13, ///< 5GBASE_KR
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_50GBASE_KR_CR    = 14, ///< 50GBASE_KR_CR
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_100GBASE_KR2_CR2 = 15, ///< 100GBASE_KR2_CR2
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_200GBASE_KR4_CR4 = 16, ///< 200GBASE_KR4_CR4
    IFCS_DEVPORT_AN_BP_TECH_ABILITY_MAX_COUNT        = 17, ///< MAX_COUNT
} ifcs_devport_an_bp_tech_ability_t;

/**
 * @brief TTL Check Profile
 */
typedef enum ifcs_ttl_check_profile_e {

    IFCS_TTL_CHECK_PROFILE_0 = 0, ///< 0
    IFCS_TTL_CHECK_PROFILE_1 = 1, ///< 1
} ifcs_ttl_check_profile_t;

/**
 * @brief Specifies what type of ethernet flow control to assume when computing inflight buffer space
 */
typedef enum ifcs_ll_inflight_computation_fc_mode_e {

    IFCS_LL_INFLIGHT_COMPUTATION_FC_MODE_PFC   = 0, ///< Priority-based flow control is assumed when computing inflight buffer space
    IFCS_LL_INFLIGHT_COMPUTATION_FC_MODE_PAUSE = 1, ///< PAUSE flow control is assumed when computing inflight buffer space
} ifcs_ll_inflight_computation_fc_mode_t;

/**
 * @brief Prefix routes to hash table - level
 */
typedef enum ifcs_pth_level_e {

    IFCS_PTH_LEVEL_NONE = 0, ///< Disables this feature
    IFCS_PTH_LEVEL_ONE  = 1, ///< Places /127 in Host table by expanding
    IFCS_PTH_LEVEL_TWO  = 2, ///< PLaces /126 and /127 in Host table by expanding
} ifcs_pth_level_t;

typedef uint64_t ifcs_uint64_t;

typedef uint32_t ifcs_uint32_t;

typedef int32_t ifcs_int32_t;

typedef uint16_t ifcs_uint16_t;

typedef uint8_t ifcs_uint8_t;

typedef int8_t ifcs_int8_t;

typedef float ifcs_flt_t;

/**
 * @brief To return time in second, microsecond, and nanosecond format
 */
typedef struct ifcs_time_s {

    ifcs_uint32_t tv_sec;             ///< time value in seconds
    ifcs_uint32_t tv_usec;            ///< time value in microseconds
    ifcs_uint32_t tv_nsec;            ///< time value in nanoseconds
    ifcs_uint8_t  _dirty_tv_sec : 1;  ///< indicates if user has set tv_sec
    ifcs_uint8_t  _dirty_tv_usec : 1; ///< indicates if user has set tv_usec
    ifcs_uint8_t  _dirty_tv_nsec : 1; ///< indicates if user has set tv_nsec
} ifcs_time_t;

/**
 * @brief Initialize the time structure
 *
 * @param [in,out] time_p    - time
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_time_t_init(ifcs_time_t *time_p);
/**
 * @brief Set the time structure with tv_sec
 *
 * @param [in,out] time_p    - time
 * @param [in]     tv_sec    - tv_sec
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_time_t_tv_sec_set(ifcs_time_t *time_p, ifcs_uint32_t tv_sec);

/**
 * @brief Get the time structure with tv_sec
 *
 * @param [in,out] time_p    - time
 * @param [in]     tv_sec_p  - tv_sec
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_time_t_tv_sec_get(ifcs_time_t *time_p, ifcs_uint32_t *tv_sec_p);

/**
 * @brief Set the time structure with tv_usec
 *
 * @param [in,out] time_p    - time
 * @param [in]     tv_usec   - tv_usec
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_time_t_tv_usec_set(ifcs_time_t *time_p, ifcs_uint32_t tv_usec);

/**
 * @brief Get the time structure with tv_usec
 *
 * @param [in,out] time_p    - time
 * @param [in]     tv_usec_p - tv_usec
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_time_t_tv_usec_get(ifcs_time_t *time_p, ifcs_uint32_t *tv_usec_p);

/**
 * @brief Set the time structure with tv_nsec
 *
 * @param [in,out] time_p    - time
 * @param [in]     tv_nsec   - tv_nsec
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_time_t_tv_nsec_set(ifcs_time_t *time_p, ifcs_uint32_t tv_nsec);

/**
 * @brief Get the time structure with tv_nsec
 *
 * @param [in,out] time_p    - time
 * @param [in]     tv_nsec_p - tv_nsec
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_time_t_tv_nsec_get(ifcs_time_t *time_p, ifcs_uint32_t *tv_nsec_p);

/**
 * @brief To store detailed stats attributes
 */
typedef struct ifcs_counter_s {

    uint64_t               counter;                    ///< what was originally counters_p in stats_get
    ifcs_stats_class_t     stats_class;                ///< stats class (drop/error/regular)
    ifcs_stats_direction_t stats_direction;            ///< stats direction (rx/tx/none)
    ifcs_time_t            timestamp;                  ///< time at which the stat was last updated
    ifcs_bool_t            valid;                      ///< indicates if the stat is valid within its context
    ifcs_uint8_t           _dirty_counter : 1;         ///< indicates if user has set counter
    ifcs_uint8_t           _dirty_stats_class : 1;     ///< indicates if user has set stats_class
    ifcs_uint8_t           _dirty_stats_direction : 1; ///< indicates if user has set stats_direction
    ifcs_uint8_t           _dirty_timestamp : 1;       ///< indicates if user has set timestamp
    ifcs_uint8_t           _dirty_valid : 1;           ///< indicates if user has set valid
} ifcs_counter_t;

/**
 * @brief Initialize the counter structure
 *
 * @param [in,out] counter_p         - counter
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_counter_t_init(ifcs_counter_t *counter_p);
/**
 * @brief Set the counter structure with stats_class
 *
 * @param [in,out] counter_p         - counter
 * @param [in]     stats_class       - stats_class
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_counter_t_stats_class_set(ifcs_counter_t *counter_p, ifcs_stats_class_t stats_class);

/**
 * @brief Get the counter structure with stats_class
 *
 * @param [in,out] counter_p         - counter
 * @param [in]     stats_class_p     - stats_class
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_counter_t_stats_class_get(ifcs_counter_t *counter_p, ifcs_stats_class_t *stats_class_p);

/**
 * @brief Set the counter structure with stats_direction
 *
 * @param [in,out] counter_p         - counter
 * @param [in]     stats_direction   - stats_direction
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_counter_t_stats_direction_set(ifcs_counter_t *counter_p, ifcs_stats_direction_t stats_direction);

/**
 * @brief Get the counter structure with stats_direction
 *
 * @param [in,out] counter_p         - counter
 * @param [in]     stats_direction_p - stats_direction
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_counter_t_stats_direction_get(ifcs_counter_t *counter_p, ifcs_stats_direction_t *stats_direction_p);

/**
 * @brief Set the counter structure with timestamp
 *
 * @param [in,out] counter_p         - counter
 * @param [in]     timestamp_p       - timestamp
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_counter_t_timestamp_set(ifcs_counter_t *counter_p, ifcs_time_t *timestamp_p);

/**
 * @brief Get the counter structure with timestamp
 *
 * @param [in,out] counter_p         - counter
 * @param [in]     timestamp_p       - timestamp
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_counter_t_timestamp_get(ifcs_counter_t *counter_p, ifcs_time_t *timestamp_p);

/**
 * @brief Set the counter structure with valid
 *
 * @param [in,out] counter_p         - counter
 * @param [in]     valid             - valid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_counter_t_valid_set(ifcs_counter_t *counter_p, ifcs_bool_t valid);

/**
 * @brief Get the counter structure with valid
 *
 * @param [in,out] counter_p         - counter
 * @param [in]     valid_p           - valid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_counter_t_valid_get(ifcs_counter_t *counter_p, ifcs_bool_t *valid_p);

typedef void ifcs_void_t;

typedef ifcs_void_t *ifcs_void_p_t;

/**
 * @brief list of uint8
 */
typedef struct ifcs_u8_list_s {

    uint32_t      count; ///< count
    ifcs_uint8_t *arr;   ///< list of uint8
} ifcs_u8_list_t;

/**
 * @brief list of uint8
 */
typedef struct ifcs_string_s {

    uint32_t      count; ///< count
    ifcs_uint8_t *arr;   ///< list of uint8
} ifcs_string_t;

/**
 * @brief list of int8
 */
typedef struct ifcs_i8_list_s {

    uint32_t     count; ///< count
    ifcs_int8_t *arr;   ///< list of int8
} ifcs_i8_list_t;

/**
 * @brief list of int32
 */
typedef struct ifcs_i32_list_s {

    uint32_t      count; ///< count
    ifcs_int32_t *arr;   ///< list of int32
} ifcs_i32_list_t;

/**
 * @brief list of uint32
 */
typedef struct ifcs_u32_list_s {

    uint32_t       count; ///< count
    ifcs_uint32_t *arr;   ///< list of uint32
} ifcs_u32_list_t;

/**
 * @brief list of uint64
 */
typedef struct ifcs_u64_list_s {

    uint32_t       count; ///< count
    ifcs_uint64_t *arr;   ///< list of uint64
} ifcs_u64_list_t;

/**
 * @brief list of flt
 */
typedef struct ifcs_flt_list_s {

    uint32_t    count; ///< count
    ifcs_flt_t *arr;   ///< list of flt
} ifcs_flt_list_t;

typedef uint32_t ifcs_devport_t;

typedef ifcs_devport_t *ifcs_devport_p_t;

/**
 * @brief List of devports
 */
typedef struct ifcs_devport_list_s {

    uint32_t        count; ///< count
    ifcs_devport_t *arr;   ///< List of devports
} ifcs_devport_list_t;

typedef uint8_t ifcs_ib_t;

/**
 * @brief Inno Block(IB) id list
 */
typedef struct ifcs_ib_list_s {

    uint32_t   count; ///< count
    ifcs_ib_t *arr;   ///< Inno Block(IB) id list
} ifcs_ib_list_t;

typedef ifcs_uint32_t ifcs_partition_id_t;

typedef ifcs_uint32_t ifcs_sysport_t;

typedef ifcs_uint32_t ifcs_node_id_t;

typedef uint32_t ifcs_cpu_queue_t;

typedef uint32_t ifcs_queue_id_t;

/**
 * @brief List of CPU queues
 */
typedef struct ifcs_cpu_queue_list_s {

    uint32_t          count; ///< count
    ifcs_cpu_queue_t *arr;   ///< List of CPU queues
} ifcs_cpu_queue_list_t;

typedef uint32_t ifcs_tc_t;

typedef ifcs_uint32_t ifcs_attr_id_t;

/**
 * @brief api params
 */
typedef struct ifcs_api_params_s {

    ifcs_api_param_flags_t flags;                  ///< defines the API behavior
    ifcs_uint64_t          start_index;            ///< Start the operation from this index( use this with IFCS_API_PARAM_FLAGS_START_INDEX flag)
    ifcs_uint8_t           _dirty_flags : 1;       ///< indicates if user has set flags
    ifcs_uint8_t           _dirty_start_index : 1; ///< indicates if user has set start_index
} ifcs_api_params_t;

/**
 * @brief Initialize the api_params structure
 *
 * @param [in,out] api_params_p  - api_params
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_api_params_t_init(ifcs_api_params_t *api_params_p);
/**
 * @brief Set the api_params structure with flags
 *
 * @param [in,out] api_params_p  - api_params
 * @param [in]     flags         - flags
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_api_params_t_flags_set(ifcs_api_params_t *api_params_p, ifcs_api_param_flags_t flags);

/**
 * @brief Get the api_params structure with flags
 *
 * @param [in,out] api_params_p  - api_params
 * @param [in]     flags_p       - flags
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_api_params_t_flags_get(ifcs_api_params_t *api_params_p, ifcs_api_param_flags_t *flags_p);

/**
 * @brief Set the api_params structure with start_index
 *
 * @param [in,out] api_params_p  - api_params
 * @param [in]     start_index   - start_index
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_api_params_t_start_index_set(ifcs_api_params_t *api_params_p, ifcs_uint64_t start_index);

/**
 * @brief Get the api_params structure with start_index
 *
 * @param [in,out] api_params_p  - api_params
 * @param [in]     start_index_p - start_index
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_api_params_t_start_index_get(ifcs_api_params_t *api_params_p, ifcs_uint64_t *start_index_p);

typedef ifcs_api_params_t *ifcs_api_params_p_t;

typedef ifcs_uint8_t ifcs_char_t;

typedef ifcs_uint32_t ifcs_ipv4_t;

typedef ifcs_uint8_t ifcs_ipv6_t[16];

/**
 * @brief Ip address
 */
typedef union ifcs_ip_addr_u {

    ifcs_ipv4_t ipv4; ///< IPv4 address
    ifcs_ipv6_t ipv6; ///< IPv6 address
} ifcs_ip_addr_t;

/**
 * @brief ip_address
 */
typedef struct ifcs_ip_address_s {

    ifcs_ip_addr_family_t addr_family;            ///< IP Address family
    ifcs_ip_addr_t        addr;                   ///< IP address union
    ifcs_uint8_t          _dirty_addr_family : 1; ///< indicates if user has set addr_family
    ifcs_uint8_t          _dirty_addr : 1;        ///< indicates if user has set addr
} ifcs_ip_address_t;

/**
 * @brief Initialize the ip_address structure
 *
 * @param [in,out] ip_address_p  - ip_address
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ip_address_t_init(ifcs_ip_address_t *ip_address_p);
/**
 * @brief Set the ip_address structure with addr_family
 *
 * @param [in,out] ip_address_p  - ip_address
 * @param [in]     addr_family   - addr_family
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ip_address_t_addr_family_set(ifcs_ip_address_t *ip_address_p, ifcs_ip_addr_family_t addr_family);

/**
 * @brief Get the ip_address structure with addr_family
 *
 * @param [in,out] ip_address_p  - ip_address
 * @param [in]     addr_family_p - addr_family
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ip_address_t_addr_family_get(ifcs_ip_address_t *ip_address_p, ifcs_ip_addr_family_t *addr_family_p);

/**
 * @brief Set the ip_address structure with addr
 *
 * @param [in,out] ip_address_p  - ip_address
 * @param [in]     addr_p        - addr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ip_address_t_addr_set(ifcs_ip_address_t *ip_address_p, ifcs_ip_addr_t *addr_p);

/**
 * @brief Get the ip_address structure with addr
 *
 * @param [in,out] ip_address_p  - ip_address
 * @param [in]     addr_p        - addr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ip_address_t_addr_get(ifcs_ip_address_t *ip_address_p, ifcs_ip_addr_t *addr_p);

/**
 * @brief IP address with prefix
 */
typedef struct ifcs_ip_prefix_s {

    ifcs_ip_addr_family_t addr_family;            ///< IP Address family
    ifcs_ip_addr_t        addr;                   ///< IP address
    ifcs_ip_addr_t        mask;                   ///< IP Mask
    ifcs_uint8_t          _dirty_addr_family : 1; ///< indicates if user has set addr_family
    ifcs_uint8_t          _dirty_addr : 1;        ///< indicates if user has set addr
    ifcs_uint8_t          _dirty_mask : 1;        ///< indicates if user has set mask
} ifcs_ip_prefix_t;

/**
 * @brief Initialize the ip_prefix structure
 *
 * @param [in,out] ip_prefix_p   - ip_prefix
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ip_prefix_t_init(ifcs_ip_prefix_t *ip_prefix_p);
/**
 * @brief Set the ip_prefix structure with addr_family
 *
 * @param [in,out] ip_prefix_p   - ip_prefix
 * @param [in]     addr_family   - addr_family
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ip_prefix_t_addr_family_set(ifcs_ip_prefix_t *ip_prefix_p, ifcs_ip_addr_family_t addr_family);

/**
 * @brief Get the ip_prefix structure with addr_family
 *
 * @param [in,out] ip_prefix_p   - ip_prefix
 * @param [in]     addr_family_p - addr_family
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ip_prefix_t_addr_family_get(ifcs_ip_prefix_t *ip_prefix_p, ifcs_ip_addr_family_t *addr_family_p);

/**
 * @brief Set the ip_prefix structure with addr
 *
 * @param [in,out] ip_prefix_p   - ip_prefix
 * @param [in]     addr_p        - addr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ip_prefix_t_addr_set(ifcs_ip_prefix_t *ip_prefix_p, ifcs_ip_addr_t *addr_p);

/**
 * @brief Get the ip_prefix structure with addr
 *
 * @param [in,out] ip_prefix_p   - ip_prefix
 * @param [in]     addr_p        - addr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ip_prefix_t_addr_get(ifcs_ip_prefix_t *ip_prefix_p, ifcs_ip_addr_t *addr_p);

/**
 * @brief Set the ip_prefix structure with mask
 *
 * @param [in,out] ip_prefix_p   - ip_prefix
 * @param [in]     mask_p        - mask
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ip_prefix_t_mask_set(ifcs_ip_prefix_t *ip_prefix_p, ifcs_ip_addr_t *mask_p);

/**
 * @brief Get the ip_prefix structure with mask
 *
 * @param [in,out] ip_prefix_p   - ip_prefix
 * @param [in]     mask_p        - mask
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ip_prefix_t_mask_get(ifcs_ip_prefix_t *ip_prefix_p, ifcs_ip_addr_t *mask_p);

typedef ifcs_uint8_t ifcs_mac_t[6];

typedef ifcs_uint32_t ifcs_handle_t;

typedef ifcs_handle_t *ifcs_handle_p_t;

/**
 * @brief List of handles
 */
typedef struct ifcs_handle_list_s {

    ifcs_uint32_t   count;            ///< Count
    ifcs_handle_p_t list;             ///< List
    ifcs_uint8_t    _dirty_count : 1; ///< indicates if user has set count
    ifcs_uint8_t    _dirty_list : 1;  ///< indicates if user has set list
} ifcs_handle_list_t;

/**
 * @brief Initialize the handle_list structure
 *
 * @param [in,out] handle_list_p - handle_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_handle_list_t_init(ifcs_handle_list_t *handle_list_p);
/**
 * @brief Set the handle_list structure with count
 *
 * @param [in,out] handle_list_p - handle_list
 * @param [in]     count         - count
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_handle_list_t_count_set(ifcs_handle_list_t *handle_list_p, ifcs_uint32_t count);

/**
 * @brief Get the handle_list structure with count
 *
 * @param [in,out] handle_list_p - handle_list
 * @param [in]     count_p       - count
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_handle_list_t_count_get(ifcs_handle_list_t *handle_list_p, ifcs_uint32_t *count_p);

/**
 * @brief Set the handle_list structure with list
 *
 * @param [in,out] handle_list_p - handle_list
 * @param [in]     list          - list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_handle_list_t_list_set(ifcs_handle_list_t *handle_list_p, ifcs_handle_p_t list);

/**
 * @brief Get the handle_list structure with list
 *
 * @param [in,out] handle_list_p - handle_list
 * @param [in]     list_p        - list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_handle_list_t_list_get(ifcs_handle_list_t *handle_list_p, ifcs_handle_p_t *list_p);

/**
 * @brief Union of usage obj enums of different API classes (used in overloaded usage_detail_get APIs)
 */
typedef union ifcs_usage_obj_u {

    ifcs_usage_obj_intf_t    intf;    ///< Intf usage objects
    ifcs_usage_obj_nexthop_t nexthop; ///< Nexthop usage objects
    ifcs_usage_obj_l3vni_t   l3vni;   ///< L3VNI usage objects
} ifcs_usage_obj_t;

/**
 * @brief Usage of IFCS API class
 */
typedef struct ifcs_usage_s {

    ifcs_uint32_t                 max;                         ///< Maximum objects that can be created
    ifcs_uint32_t                 current;                     ///< Current number of objects created
    ifcs_usage_obj_api_class_id_t obj_api_class_id;            ///< API class for which usage is fetched (used in overloaded usage_detail_get APIs)
    ifcs_usage_obj_t              obj_type;                    ///< Object type for which usage is fetched (used in overloaded usage_detail_get APIs)
    ifcs_uint32_t                 available;                   ///< Available number of objects
    ifcs_uint8_t                  _dirty_max : 1;              ///< indicates if user has set max
    ifcs_uint8_t                  _dirty_current : 1;          ///< indicates if user has set current
    ifcs_uint8_t                  _dirty_obj_api_class_id : 1; ///< indicates if user has set obj_api_class_id
    ifcs_uint8_t                  _dirty_obj_type : 1;         ///< indicates if user has set obj_type
    ifcs_uint8_t                  _dirty_available : 1;        ///< indicates if user has set available
} ifcs_usage_t;

/**
 * @brief Initialize the usage structure
 *
 * @param [in,out] usage_p            - usage
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_usage_t_init(ifcs_usage_t *usage_p);
/**
 * @brief Set the usage structure with max
 *
 * @param [in,out] usage_p            - usage
 * @param [in]     max                - max
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_usage_t_max_set(ifcs_usage_t *usage_p, ifcs_uint32_t max);

/**
 * @brief Get the usage structure with max
 *
 * @param [in,out] usage_p            - usage
 * @param [in]     max_p              - max
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_usage_t_max_get(ifcs_usage_t *usage_p, ifcs_uint32_t *max_p);

/**
 * @brief Set the usage structure with current
 *
 * @param [in,out] usage_p            - usage
 * @param [in]     current            - current
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_usage_t_current_set(ifcs_usage_t *usage_p, ifcs_uint32_t current);

/**
 * @brief Get the usage structure with current
 *
 * @param [in,out] usage_p            - usage
 * @param [in]     current_p          - current
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_usage_t_current_get(ifcs_usage_t *usage_p, ifcs_uint32_t *current_p);

/**
 * @brief Set the usage structure with obj_api_class_id
 *
 * @param [in,out] usage_p            - usage
 * @param [in]     obj_api_class_id   - obj_api_class_id
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_usage_t_obj_api_class_id_set(ifcs_usage_t *usage_p, ifcs_usage_obj_api_class_id_t obj_api_class_id);

/**
 * @brief Get the usage structure with obj_api_class_id
 *
 * @param [in,out] usage_p            - usage
 * @param [in]     obj_api_class_id_p - obj_api_class_id
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_usage_t_obj_api_class_id_get(ifcs_usage_t *usage_p, ifcs_usage_obj_api_class_id_t *obj_api_class_id_p);

/**
 * @brief Set the usage structure with obj_type
 *
 * @param [in,out] usage_p            - usage
 * @param [in]     obj_type_p         - obj_type
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_usage_t_obj_type_set(ifcs_usage_t *usage_p, ifcs_usage_obj_t *obj_type_p);

/**
 * @brief Get the usage structure with obj_type
 *
 * @param [in,out] usage_p            - usage
 * @param [in]     obj_type_p         - obj_type
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_usage_t_obj_type_get(ifcs_usage_t *usage_p, ifcs_usage_obj_t *obj_type_p);

/**
 * @brief Set the usage structure with available
 *
 * @param [in,out] usage_p            - usage
 * @param [in]     available          - available
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_usage_t_available_set(ifcs_usage_t *usage_p, ifcs_uint32_t available);

/**
 * @brief Get the usage structure with available
 *
 * @param [in,out] usage_p            - usage
 * @param [in]     available_p        - available
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_usage_t_available_get(ifcs_usage_t *usage_p, ifcs_uint32_t *available_p);

/**
 * @brief Struct containing TC,DP fields
 */
typedef struct ifcs_qos_tc_dp_s {

    ifcs_uint32_t tc;            ///< TC field value
    ifcs_uint32_t dp;            ///< DP field value
    ifcs_uint8_t  _dirty_tc : 1; ///< indicates if user has set tc
    ifcs_uint8_t  _dirty_dp : 1; ///< indicates if user has set dp
} ifcs_qos_tc_dp_t;

/**
 * @brief Initialize the qos_tc_dp structure
 *
 * @param [in,out] qos_tc_dp_p - qos_tc_dp
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_tc_dp_t_init(ifcs_qos_tc_dp_t *qos_tc_dp_p);
/**
 * @brief Set the qos_tc_dp structure with tc
 *
 * @param [in,out] qos_tc_dp_p - qos_tc_dp
 * @param [in]     tc          - tc
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_tc_dp_t_tc_set(ifcs_qos_tc_dp_t *qos_tc_dp_p, ifcs_uint32_t tc);

/**
 * @brief Get the qos_tc_dp structure with tc
 *
 * @param [in,out] qos_tc_dp_p - qos_tc_dp
 * @param [in]     tc_p        - tc
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_tc_dp_t_tc_get(ifcs_qos_tc_dp_t *qos_tc_dp_p, ifcs_uint32_t *tc_p);

/**
 * @brief Set the qos_tc_dp structure with dp
 *
 * @param [in,out] qos_tc_dp_p - qos_tc_dp
 * @param [in]     dp          - dp
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_tc_dp_t_dp_set(ifcs_qos_tc_dp_t *qos_tc_dp_p, ifcs_uint32_t dp);

/**
 * @brief Get the qos_tc_dp structure with dp
 *
 * @param [in,out] qos_tc_dp_p - qos_tc_dp
 * @param [in]     dp_p        - dp
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_tc_dp_t_dp_get(ifcs_qos_tc_dp_t *qos_tc_dp_p, ifcs_uint32_t *dp_p);

/**
 * @brief Struct containing DOT1P,CFI fields
 */
typedef struct ifcs_qos_dot1p_cfi_s {

    ifcs_uint32_t dot1p;            ///< DOT1P field value
    ifcs_uint8_t  cfi;              ///< CFI field value
    ifcs_uint8_t  _dirty_dot1p : 1; ///< indicates if user has set dot1p
    ifcs_uint8_t  _dirty_cfi : 1;   ///< indicates if user has set cfi
} ifcs_qos_dot1p_cfi_t;

/**
 * @brief Initialize the qos_dot1p_cfi structure
 *
 * @param [in,out] qos_dot1p_cfi_p - qos_dot1p_cfi
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_dot1p_cfi_t_init(ifcs_qos_dot1p_cfi_t *qos_dot1p_cfi_p);
/**
 * @brief Set the qos_dot1p_cfi structure with dot1p
 *
 * @param [in,out] qos_dot1p_cfi_p - qos_dot1p_cfi
 * @param [in]     dot1p           - dot1p
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_dot1p_cfi_t_dot1p_set(ifcs_qos_dot1p_cfi_t *qos_dot1p_cfi_p, ifcs_uint32_t dot1p);

/**
 * @brief Get the qos_dot1p_cfi structure with dot1p
 *
 * @param [in,out] qos_dot1p_cfi_p - qos_dot1p_cfi
 * @param [in]     dot1p_p         - dot1p
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_dot1p_cfi_t_dot1p_get(ifcs_qos_dot1p_cfi_t *qos_dot1p_cfi_p, ifcs_uint32_t *dot1p_p);

/**
 * @brief Set the qos_dot1p_cfi structure with cfi
 *
 * @param [in,out] qos_dot1p_cfi_p - qos_dot1p_cfi
 * @param [in]     cfi             - cfi
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_dot1p_cfi_t_cfi_set(ifcs_qos_dot1p_cfi_t *qos_dot1p_cfi_p, ifcs_uint8_t cfi);

/**
 * @brief Get the qos_dot1p_cfi structure with cfi
 *
 * @param [in,out] qos_dot1p_cfi_p - qos_dot1p_cfi
 * @param [in]     cfi_p           - cfi
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_dot1p_cfi_t_cfi_get(ifcs_qos_dot1p_cfi_t *qos_dot1p_cfi_p, ifcs_uint8_t *cfi_p);

/**
 * @brief Union of different QOS map src/value fields
 */
typedef union ifcs_qos_map_fields_u {

    ifcs_qos_tc_dp_t     tc_dp;     ///< TC, DP value
    ifcs_uint32_t        dscp;      ///< DSCP value
    ifcs_qos_dot1p_cfi_t dot1p_cfi; ///< DOT1P, CFI value
    ifcs_uint32_t        exp;       ///< EXP value
    ifcs_uint32_t        queue;     ///< Queue number
} ifcs_qos_map_fields_t;

/**
 * @brief QOS mapping
 */
typedef struct ifcs_qos_map_s {

    ifcs_qos_map_fields_t map_src;              ///< Input parameters to match
    ifcs_qos_map_fields_t map_value;            ///< Output map parameters
    ifcs_uint8_t          _dirty_map_src : 1;   ///< indicates if user has set map_src
    ifcs_uint8_t          _dirty_map_value : 1; ///< indicates if user has set map_value
} ifcs_qos_map_t;

/**
 * @brief Initialize the qos_map structure
 *
 * @param [in,out] qos_map_p   - qos_map
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_map_t_init(ifcs_qos_map_t *qos_map_p);
/**
 * @brief Set the qos_map structure with map_src
 *
 * @param [in,out] qos_map_p   - qos_map
 * @param [in]     map_src_p   - map_src
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_map_t_map_src_set(ifcs_qos_map_t *qos_map_p, ifcs_qos_map_fields_t *map_src_p);

/**
 * @brief Get the qos_map structure with map_src
 *
 * @param [in,out] qos_map_p   - qos_map
 * @param [in]     map_src_p   - map_src
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_map_t_map_src_get(ifcs_qos_map_t *qos_map_p, ifcs_qos_map_fields_t *map_src_p);

/**
 * @brief Set the qos_map structure with map_value
 *
 * @param [in,out] qos_map_p   - qos_map
 * @param [in]     map_value_p - map_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_map_t_map_value_set(ifcs_qos_map_t *qos_map_p, ifcs_qos_map_fields_t *map_value_p);

/**
 * @brief Get the qos_map structure with map_value
 *
 * @param [in,out] qos_map_p   - qos_map
 * @param [in]     map_value_p - map_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_map_t_map_value_get(ifcs_qos_map_t *qos_map_p, ifcs_qos_map_fields_t *map_value_p);

/**
 * @brief Dynamic list of QOS map
 */
typedef struct ifcs_qos_map_list_s {

    uint32_t        count; ///< count
    ifcs_qos_map_t *arr;   ///< Dynamic list of QOS map
} ifcs_qos_map_list_t;

/**
 * @brief QOS map information
 */
typedef struct ifcs_qos_map_info_s {

    ifcs_qos_map_type_t type;            ///< QOS map type
    ifcs_qos_map_list_t list;            ///< Map list
    ifcs_uint8_t        _dirty_type : 1; ///< indicates if user has set type
    ifcs_uint8_t        _dirty_list : 1; ///< indicates if user has set list
} ifcs_qos_map_info_t;

/**
 * @brief Initialize the qos_map_info structure
 *
 * @param [in,out] qos_map_info_p - qos_map_info
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_map_info_t_init(ifcs_qos_map_info_t *qos_map_info_p);
/**
 * @brief Set the qos_map_info structure with type
 *
 * @param [in,out] qos_map_info_p - qos_map_info
 * @param [in]     type           - type
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_map_info_t_type_set(ifcs_qos_map_info_t *qos_map_info_p, ifcs_qos_map_type_t type);

/**
 * @brief Get the qos_map_info structure with type
 *
 * @param [in,out] qos_map_info_p - qos_map_info
 * @param [in]     type_p         - type
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_map_info_t_type_get(ifcs_qos_map_info_t *qos_map_info_p, ifcs_qos_map_type_t *type_p);

/**
 * @brief Set the qos_map_info structure with list
 *
 * @param [in,out] qos_map_info_p - qos_map_info
 * @param [in]     list_p         - list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_map_info_t_list_set(ifcs_qos_map_info_t *qos_map_info_p, ifcs_qos_map_list_t *list_p);

/**
 * @brief Get the qos_map_info structure with list
 *
 * @param [in,out] qos_map_info_p - qos_map_info
 * @param [in]     list_p         - list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_qos_map_info_t_list_get(ifcs_qos_map_info_t *qos_map_info_p, ifcs_qos_map_list_t *list_p);

/**
 * @brief Copy to CPU policy for a given API object
 */
typedef struct ifcs_ctc_policy_s {

    ifcs_copy_to_cpu_t ctc_action;             ///< Copy to CPU action
    ifcs_handle_t      trap_handle;            ///< Trap handle
    ifcs_uint8_t       _dirty_ctc_action : 1;  ///< indicates if user has set ctc_action
    ifcs_uint8_t       _dirty_trap_handle : 1; ///< indicates if user has set trap_handle
} ifcs_ctc_policy_t;

/**
 * @brief Initialize the ctc_policy structure
 *
 * @param [in,out] ctc_policy_p  - ctc_policy
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ctc_policy_t_init(ifcs_ctc_policy_t *ctc_policy_p);
/**
 * @brief Set the ctc_policy structure with ctc_action
 *
 * @param [in,out] ctc_policy_p  - ctc_policy
 * @param [in]     ctc_action    - ctc_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ctc_policy_t_ctc_action_set(ifcs_ctc_policy_t *ctc_policy_p, ifcs_copy_to_cpu_t ctc_action);

/**
 * @brief Get the ctc_policy structure with ctc_action
 *
 * @param [in,out] ctc_policy_p  - ctc_policy
 * @param [in]     ctc_action_p  - ctc_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ctc_policy_t_ctc_action_get(ifcs_ctc_policy_t *ctc_policy_p, ifcs_copy_to_cpu_t *ctc_action_p);

/**
 * @brief Set the ctc_policy structure with trap_handle
 *
 * @param [in,out] ctc_policy_p  - ctc_policy
 * @param [in]     trap_handle   - trap_handle
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ctc_policy_t_trap_handle_set(ifcs_ctc_policy_t *ctc_policy_p, ifcs_handle_t trap_handle);

/**
 * @brief Get the ctc_policy structure with trap_handle
 *
 * @param [in,out] ctc_policy_p  - ctc_policy
 * @param [in]     trap_handle_p - trap_handle
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ctc_policy_t_trap_handle_get(ifcs_ctc_policy_t *ctc_policy_p, ifcs_handle_t *trap_handle_p);

/**
 * @brief Forward policy for a given API object
 */
typedef struct ifcs_fwd_policy_s {

    ifcs_fwd_action_t fwd_action;                ///< Packet forward action
    ifcs_handle_t     pp_drop_reason;            ///< Packet processing drop reason handle
    ifcs_uint8_t      _dirty_fwd_action : 1;     ///< indicates if user has set fwd_action
    ifcs_uint8_t      _dirty_pp_drop_reason : 1; ///< indicates if user has set pp_drop_reason
} ifcs_fwd_policy_t;

/**
 * @brief Initialize the fwd_policy structure
 *
 * @param [in,out] fwd_policy_p     - fwd_policy
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fwd_policy_t_init(ifcs_fwd_policy_t *fwd_policy_p);
/**
 * @brief Set the fwd_policy structure with fwd_action
 *
 * @param [in,out] fwd_policy_p     - fwd_policy
 * @param [in]     fwd_action       - fwd_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fwd_policy_t_fwd_action_set(ifcs_fwd_policy_t *fwd_policy_p, ifcs_fwd_action_t fwd_action);

/**
 * @brief Get the fwd_policy structure with fwd_action
 *
 * @param [in,out] fwd_policy_p     - fwd_policy
 * @param [in]     fwd_action_p     - fwd_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fwd_policy_t_fwd_action_get(ifcs_fwd_policy_t *fwd_policy_p, ifcs_fwd_action_t *fwd_action_p);

/**
 * @brief Set the fwd_policy structure with pp_drop_reason
 *
 * @param [in,out] fwd_policy_p     - fwd_policy
 * @param [in]     pp_drop_reason   - pp_drop_reason
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fwd_policy_t_pp_drop_reason_set(ifcs_fwd_policy_t *fwd_policy_p, ifcs_handle_t pp_drop_reason);

/**
 * @brief Get the fwd_policy structure with pp_drop_reason
 *
 * @param [in,out] fwd_policy_p     - fwd_policy
 * @param [in]     pp_drop_reason_p - pp_drop_reason
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fwd_policy_t_pp_drop_reason_get(ifcs_fwd_policy_t *fwd_policy_p, ifcs_handle_t *pp_drop_reason_p);

/**
 * @brief Traffic_Monitor policy
 */
typedef struct ifcs_traffic_monitor_policy_s {

    ifcs_traffic_monitor_action_t    traffic_monitor_action;               ///< Traffic monitor action
    ifcs_handle_t                    collector_set;                        ///< Collector set
    ifcs_traffic_monitor_container_t traffic_monitor_container;            ///< Traffic_Monitor container
    ifcs_uint32_t                    sampling_rate;                        ///< sFlow sampling rate expressed as 1 in every N packets, where this parameter specifies N. For example, a rate value of 10,000 results in sFlow sampling rate of 1 every 10,000 packets (on average)
    ifcs_uint8_t                     _dirty_traffic_monitor_action : 1;    ///< indicates if user has set traffic_monitor_action
    ifcs_uint8_t                     _dirty_collector_set : 1;             ///< indicates if user has set collector_set
    ifcs_uint8_t                     _dirty_traffic_monitor_container : 1; ///< indicates if user has set traffic_monitor_container
    ifcs_uint8_t                     _dirty_sampling_rate : 1;             ///< indicates if user has set sampling_rate
} ifcs_traffic_monitor_policy_t;

/**
 * @brief Initialize the traffic_monitor_policy structure
 *
 * @param [in,out] traffic_monitor_policy_p    - traffic_monitor_policy
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_traffic_monitor_policy_t_init(ifcs_traffic_monitor_policy_t *traffic_monitor_policy_p);
/**
 * @brief Set the traffic_monitor_policy structure with traffic_monitor_action
 *
 * @param [in,out] traffic_monitor_policy_p    - traffic_monitor_policy
 * @param [in]     traffic_monitor_action      - traffic_monitor_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_traffic_monitor_policy_t_traffic_monitor_action_set(ifcs_traffic_monitor_policy_t *traffic_monitor_policy_p, ifcs_traffic_monitor_action_t traffic_monitor_action);

/**
 * @brief Get the traffic_monitor_policy structure with traffic_monitor_action
 *
 * @param [in,out] traffic_monitor_policy_p    - traffic_monitor_policy
 * @param [in]     traffic_monitor_action_p    - traffic_monitor_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_traffic_monitor_policy_t_traffic_monitor_action_get(ifcs_traffic_monitor_policy_t *traffic_monitor_policy_p, ifcs_traffic_monitor_action_t *traffic_monitor_action_p);

/**
 * @brief Set the traffic_monitor_policy structure with collector_set
 *
 * @param [in,out] traffic_monitor_policy_p    - traffic_monitor_policy
 * @param [in]     collector_set               - collector_set
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_traffic_monitor_policy_t_collector_set_set(ifcs_traffic_monitor_policy_t *traffic_monitor_policy_p, ifcs_handle_t collector_set);

/**
 * @brief Get the traffic_monitor_policy structure with collector_set
 *
 * @param [in,out] traffic_monitor_policy_p    - traffic_monitor_policy
 * @param [in]     collector_set_p             - collector_set
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_traffic_monitor_policy_t_collector_set_get(ifcs_traffic_monitor_policy_t *traffic_monitor_policy_p, ifcs_handle_t *collector_set_p);

/**
 * @brief Set the traffic_monitor_policy structure with traffic_monitor_container
 *
 * @param [in,out] traffic_monitor_policy_p    - traffic_monitor_policy
 * @param [in]     traffic_monitor_container   - traffic_monitor_container
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_traffic_monitor_policy_t_traffic_monitor_container_set(ifcs_traffic_monitor_policy_t *traffic_monitor_policy_p, ifcs_traffic_monitor_container_t traffic_monitor_container);

/**
 * @brief Get the traffic_monitor_policy structure with traffic_monitor_container
 *
 * @param [in,out] traffic_monitor_policy_p    - traffic_monitor_policy
 * @param [in]     traffic_monitor_container_p - traffic_monitor_container
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_traffic_monitor_policy_t_traffic_monitor_container_get(ifcs_traffic_monitor_policy_t *traffic_monitor_policy_p, ifcs_traffic_monitor_container_t *traffic_monitor_container_p);

/**
 * @brief Set the traffic_monitor_policy structure with sampling_rate
 *
 * @param [in,out] traffic_monitor_policy_p    - traffic_monitor_policy
 * @param [in]     sampling_rate               - sampling_rate
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_traffic_monitor_policy_t_sampling_rate_set(ifcs_traffic_monitor_policy_t *traffic_monitor_policy_p, ifcs_uint32_t sampling_rate);

/**
 * @brief Get the traffic_monitor_policy structure with sampling_rate
 *
 * @param [in,out] traffic_monitor_policy_p    - traffic_monitor_policy
 * @param [in]     sampling_rate_p             - sampling_rate
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_traffic_monitor_policy_t_sampling_rate_get(ifcs_traffic_monitor_policy_t *traffic_monitor_policy_p, ifcs_uint32_t *sampling_rate_p);

/**
 * @brief BDC policy
 */
typedef struct ifcs_bdc_policy_s {

    ifcs_handle_t collector_set;                 ///< Collector set
    ifcs_handle_t visibility_sampler;            ///< Visibility sampler
    ifcs_uint8_t  _dirty_collector_set : 1;      ///< indicates if user has set collector_set
    ifcs_uint8_t  _dirty_visibility_sampler : 1; ///< indicates if user has set visibility_sampler
} ifcs_bdc_policy_t;

/**
 * @brief Initialize the bdc_policy structure
 *
 * @param [in,out] bdc_policy_p         - bdc_policy
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_bdc_policy_t_init(ifcs_bdc_policy_t *bdc_policy_p);
/**
 * @brief Set the bdc_policy structure with collector_set
 *
 * @param [in,out] bdc_policy_p         - bdc_policy
 * @param [in]     collector_set        - collector_set
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_bdc_policy_t_collector_set_set(ifcs_bdc_policy_t *bdc_policy_p, ifcs_handle_t collector_set);

/**
 * @brief Get the bdc_policy structure with collector_set
 *
 * @param [in,out] bdc_policy_p         - bdc_policy
 * @param [in]     collector_set_p      - collector_set
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_bdc_policy_t_collector_set_get(ifcs_bdc_policy_t *bdc_policy_p, ifcs_handle_t *collector_set_p);

/**
 * @brief Set the bdc_policy structure with visibility_sampler
 *
 * @param [in,out] bdc_policy_p         - bdc_policy
 * @param [in]     visibility_sampler   - visibility_sampler
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_bdc_policy_t_visibility_sampler_set(ifcs_bdc_policy_t *bdc_policy_p, ifcs_handle_t visibility_sampler);

/**
 * @brief Get the bdc_policy structure with visibility_sampler
 *
 * @param [in,out] bdc_policy_p         - bdc_policy
 * @param [in]     visibility_sampler_p - visibility_sampler
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_bdc_policy_t_visibility_sampler_get(ifcs_bdc_policy_t *bdc_policy_p, ifcs_handle_t *visibility_sampler_p);

/**
 * @brief High delay policy
 */
typedef struct ifcs_hdc_policy_s {

    ifcs_handle_t delay_threshold;               ///< High delay threshold
    ifcs_handle_t visibility_sampler;            ///< Visibility sampler
    ifcs_handle_t collector_set;                 ///< Collector set
    ifcs_uint8_t  _dirty_delay_threshold : 1;    ///< indicates if user has set delay_threshold
    ifcs_uint8_t  _dirty_visibility_sampler : 1; ///< indicates if user has set visibility_sampler
    ifcs_uint8_t  _dirty_collector_set : 1;      ///< indicates if user has set collector_set
} ifcs_hdc_policy_t;

/**
 * @brief Initialize the hdc_policy structure
 *
 * @param [in,out] hdc_policy_p         - hdc_policy
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_hdc_policy_t_init(ifcs_hdc_policy_t *hdc_policy_p);
/**
 * @brief Set the hdc_policy structure with delay_threshold
 *
 * @param [in,out] hdc_policy_p         - hdc_policy
 * @param [in]     delay_threshold      - delay_threshold
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_hdc_policy_t_delay_threshold_set(ifcs_hdc_policy_t *hdc_policy_p, ifcs_handle_t delay_threshold);

/**
 * @brief Get the hdc_policy structure with delay_threshold
 *
 * @param [in,out] hdc_policy_p         - hdc_policy
 * @param [in]     delay_threshold_p    - delay_threshold
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_hdc_policy_t_delay_threshold_get(ifcs_hdc_policy_t *hdc_policy_p, ifcs_handle_t *delay_threshold_p);

/**
 * @brief Set the hdc_policy structure with visibility_sampler
 *
 * @param [in,out] hdc_policy_p         - hdc_policy
 * @param [in]     visibility_sampler   - visibility_sampler
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_hdc_policy_t_visibility_sampler_set(ifcs_hdc_policy_t *hdc_policy_p, ifcs_handle_t visibility_sampler);

/**
 * @brief Get the hdc_policy structure with visibility_sampler
 *
 * @param [in,out] hdc_policy_p         - hdc_policy
 * @param [in]     visibility_sampler_p - visibility_sampler
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_hdc_policy_t_visibility_sampler_get(ifcs_hdc_policy_t *hdc_policy_p, ifcs_handle_t *visibility_sampler_p);

/**
 * @brief Set the hdc_policy structure with collector_set
 *
 * @param [in,out] hdc_policy_p         - hdc_policy
 * @param [in]     collector_set        - collector_set
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_hdc_policy_t_collector_set_set(ifcs_hdc_policy_t *hdc_policy_p, ifcs_handle_t collector_set);

/**
 * @brief Get the hdc_policy structure with collector_set
 *
 * @param [in,out] hdc_policy_p         - hdc_policy
 * @param [in]     collector_set_p      - collector_set
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_hdc_policy_t_collector_set_get(ifcs_hdc_policy_t *hdc_policy_p, ifcs_handle_t *collector_set_p);

/**
 * @brief IPT policy
 */
typedef struct ifcs_ipt_policy_s {

    ifcs_handle_t telemetry_instance;               ///< Telemetry instance
    ifcs_uint32_t ingress_sampling_rate;            ///< IPT clone generation rate expressed as 1 in every N packets, where this parameter specifies N. For example, a rate value of 10,000 results in a clone generation rate of 1 every 10,000 packets (on average), min:1, max:(2^24 - 1), default:1
    ifcs_bool_t   ingress_enable;                   ///< Enable/Disable ingress IPT
    ifcs_handle_t egress_collector_set;             ///< Collector set associated with the IPT egress function
    ifcs_bool_t   egress_enable;                    ///< Enable/Disable egress IPT
    ifcs_uint8_t  _dirty_telemetry_instance : 1;    ///< indicates if user has set telemetry_instance
    ifcs_uint8_t  _dirty_ingress_sampling_rate : 1; ///< indicates if user has set ingress_sampling_rate
    ifcs_uint8_t  _dirty_ingress_enable : 1;        ///< indicates if user has set ingress_enable
    ifcs_uint8_t  _dirty_egress_collector_set : 1;  ///< indicates if user has set egress_collector_set
    ifcs_uint8_t  _dirty_egress_enable : 1;         ///< indicates if user has set egress_enable
} ifcs_ipt_policy_t;

/**
 * @brief Initialize the ipt_policy structure
 *
 * @param [in,out] ipt_policy_p            - ipt_policy
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ipt_policy_t_init(ifcs_ipt_policy_t *ipt_policy_p);
/**
 * @brief Set the ipt_policy structure with telemetry_instance
 *
 * @param [in,out] ipt_policy_p            - ipt_policy
 * @param [in]     telemetry_instance      - telemetry_instance
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ipt_policy_t_telemetry_instance_set(ifcs_ipt_policy_t *ipt_policy_p, ifcs_handle_t telemetry_instance);

/**
 * @brief Get the ipt_policy structure with telemetry_instance
 *
 * @param [in,out] ipt_policy_p            - ipt_policy
 * @param [in]     telemetry_instance_p    - telemetry_instance
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ipt_policy_t_telemetry_instance_get(ifcs_ipt_policy_t *ipt_policy_p, ifcs_handle_t *telemetry_instance_p);

/**
 * @brief Set the ipt_policy structure with ingress_sampling_rate
 *
 * @param [in,out] ipt_policy_p            - ipt_policy
 * @param [in]     ingress_sampling_rate   - ingress_sampling_rate
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ipt_policy_t_ingress_sampling_rate_set(ifcs_ipt_policy_t *ipt_policy_p, ifcs_uint32_t ingress_sampling_rate);

/**
 * @brief Get the ipt_policy structure with ingress_sampling_rate
 *
 * @param [in,out] ipt_policy_p            - ipt_policy
 * @param [in]     ingress_sampling_rate_p - ingress_sampling_rate
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ipt_policy_t_ingress_sampling_rate_get(ifcs_ipt_policy_t *ipt_policy_p, ifcs_uint32_t *ingress_sampling_rate_p);

/**
 * @brief Set the ipt_policy structure with ingress_enable
 *
 * @param [in,out] ipt_policy_p            - ipt_policy
 * @param [in]     ingress_enable          - ingress_enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ipt_policy_t_ingress_enable_set(ifcs_ipt_policy_t *ipt_policy_p, ifcs_bool_t ingress_enable);

/**
 * @brief Get the ipt_policy structure with ingress_enable
 *
 * @param [in,out] ipt_policy_p            - ipt_policy
 * @param [in]     ingress_enable_p        - ingress_enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ipt_policy_t_ingress_enable_get(ifcs_ipt_policy_t *ipt_policy_p, ifcs_bool_t *ingress_enable_p);

/**
 * @brief Set the ipt_policy structure with egress_collector_set
 *
 * @param [in,out] ipt_policy_p            - ipt_policy
 * @param [in]     egress_collector_set    - egress_collector_set
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ipt_policy_t_egress_collector_set_set(ifcs_ipt_policy_t *ipt_policy_p, ifcs_handle_t egress_collector_set);

/**
 * @brief Get the ipt_policy structure with egress_collector_set
 *
 * @param [in,out] ipt_policy_p            - ipt_policy
 * @param [in]     egress_collector_set_p  - egress_collector_set
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ipt_policy_t_egress_collector_set_get(ifcs_ipt_policy_t *ipt_policy_p, ifcs_handle_t *egress_collector_set_p);

/**
 * @brief Set the ipt_policy structure with egress_enable
 *
 * @param [in,out] ipt_policy_p            - ipt_policy
 * @param [in]     egress_enable           - egress_enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ipt_policy_t_egress_enable_set(ifcs_ipt_policy_t *ipt_policy_p, ifcs_bool_t egress_enable);

/**
 * @brief Get the ipt_policy structure with egress_enable
 *
 * @param [in,out] ipt_policy_p            - ipt_policy
 * @param [in]     egress_enable_p         - egress_enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ipt_policy_t_egress_enable_get(ifcs_ipt_policy_t *ipt_policy_p, ifcs_bool_t *egress_enable_p);

/**
 * @brief Attributes required to enable extended statistics
 */
typedef struct ifcs_flex_stats_attributes_s {

    ifcs_stats_mode_t counter_mode;                  ///< Mode of the counters needed
    ifcs_uint32_t     start_offset;                  ///< Start offset used to compute relative counter index
    ifcs_uint32_t     number_of_counters;            ///< Number of counters of the given type needed
    ifcs_uint8_t      _dirty_counter_mode : 1;       ///< indicates if user has set counter_mode
    ifcs_uint8_t      _dirty_start_offset : 1;       ///< indicates if user has set start_offset
    ifcs_uint8_t      _dirty_number_of_counters : 1; ///< indicates if user has set number_of_counters
} ifcs_flex_stats_attributes_t;

/**
 * @brief Initialize the flex_stats_attributes structure
 *
 * @param [in,out] flex_stats_attributes_p - flex_stats_attributes
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_flex_stats_attributes_t_init(ifcs_flex_stats_attributes_t *flex_stats_attributes_p);
/**
 * @brief Set the flex_stats_attributes structure with counter_mode
 *
 * @param [in,out] flex_stats_attributes_p - flex_stats_attributes
 * @param [in]     counter_mode            - counter_mode
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_flex_stats_attributes_t_counter_mode_set(ifcs_flex_stats_attributes_t *flex_stats_attributes_p, ifcs_stats_mode_t counter_mode);

/**
 * @brief Get the flex_stats_attributes structure with counter_mode
 *
 * @param [in,out] flex_stats_attributes_p - flex_stats_attributes
 * @param [in]     counter_mode_p          - counter_mode
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_flex_stats_attributes_t_counter_mode_get(ifcs_flex_stats_attributes_t *flex_stats_attributes_p, ifcs_stats_mode_t *counter_mode_p);

/**
 * @brief Set the flex_stats_attributes structure with start_offset
 *
 * @param [in,out] flex_stats_attributes_p - flex_stats_attributes
 * @param [in]     start_offset            - start_offset
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_flex_stats_attributes_t_start_offset_set(ifcs_flex_stats_attributes_t *flex_stats_attributes_p, ifcs_uint32_t start_offset);

/**
 * @brief Get the flex_stats_attributes structure with start_offset
 *
 * @param [in,out] flex_stats_attributes_p - flex_stats_attributes
 * @param [in]     start_offset_p          - start_offset
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_flex_stats_attributes_t_start_offset_get(ifcs_flex_stats_attributes_t *flex_stats_attributes_p, ifcs_uint32_t *start_offset_p);

/**
 * @brief Set the flex_stats_attributes structure with number_of_counters
 *
 * @param [in,out] flex_stats_attributes_p - flex_stats_attributes
 * @param [in]     number_of_counters      - number_of_counters
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_flex_stats_attributes_t_number_of_counters_set(ifcs_flex_stats_attributes_t *flex_stats_attributes_p, ifcs_uint32_t number_of_counters);

/**
 * @brief Get the flex_stats_attributes structure with number_of_counters
 *
 * @param [in,out] flex_stats_attributes_p - flex_stats_attributes
 * @param [in]     number_of_counters_p    - number_of_counters
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_flex_stats_attributes_t_number_of_counters_get(ifcs_flex_stats_attributes_t *flex_stats_attributes_p, ifcs_uint32_t *number_of_counters_p);

/**
 * @brief Ring configuration
 */
typedef struct ifcs_ring_cfg_info_s {

    ifcs_ring_type_t      ring_type;                ///< Ring type
    ifcs_ring_mgr_type_t  ring_mgr_type;            ///< Ring manager type
    ifcs_uint32_t         desc_count;               ///< Number of DMA ring descriptor entries
    ifcs_uint8_t          priority;                 ///< Priority of queue
    ifcs_cpu_queue_list_t queues;                   ///< Queues for this ring, max queue number is 48
    ifcs_uint8_t          _dirty_ring_type : 1;     ///< indicates if user has set ring_type
    ifcs_uint8_t          _dirty_ring_mgr_type : 1; ///< indicates if user has set ring_mgr_type
    ifcs_uint8_t          _dirty_desc_count : 1;    ///< indicates if user has set desc_count
    ifcs_uint8_t          _dirty_priority : 1;      ///< indicates if user has set priority
    ifcs_uint8_t          _dirty_queues : 1;        ///< indicates if user has set queues
} ifcs_ring_cfg_info_t;

/**
 * @brief Initialize the ring_cfg_info structure
 *
 * @param [in,out] ring_cfg_info_p - ring_cfg_info
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ring_cfg_info_t_init(ifcs_ring_cfg_info_t *ring_cfg_info_p);
/**
 * @brief Set the ring_cfg_info structure with ring_type
 *
 * @param [in,out] ring_cfg_info_p - ring_cfg_info
 * @param [in]     ring_type       - ring_type
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ring_cfg_info_t_ring_type_set(ifcs_ring_cfg_info_t *ring_cfg_info_p, ifcs_ring_type_t ring_type);

/**
 * @brief Get the ring_cfg_info structure with ring_type
 *
 * @param [in,out] ring_cfg_info_p - ring_cfg_info
 * @param [in]     ring_type_p     - ring_type
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ring_cfg_info_t_ring_type_get(ifcs_ring_cfg_info_t *ring_cfg_info_p, ifcs_ring_type_t *ring_type_p);

/**
 * @brief Set the ring_cfg_info structure with ring_mgr_type
 *
 * @param [in,out] ring_cfg_info_p - ring_cfg_info
 * @param [in]     ring_mgr_type   - ring_mgr_type
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ring_cfg_info_t_ring_mgr_type_set(ifcs_ring_cfg_info_t *ring_cfg_info_p, ifcs_ring_mgr_type_t ring_mgr_type);

/**
 * @brief Get the ring_cfg_info structure with ring_mgr_type
 *
 * @param [in,out] ring_cfg_info_p - ring_cfg_info
 * @param [in]     ring_mgr_type_p - ring_mgr_type
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ring_cfg_info_t_ring_mgr_type_get(ifcs_ring_cfg_info_t *ring_cfg_info_p, ifcs_ring_mgr_type_t *ring_mgr_type_p);

/**
 * @brief Set the ring_cfg_info structure with desc_count
 *
 * @param [in,out] ring_cfg_info_p - ring_cfg_info
 * @param [in]     desc_count      - desc_count
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ring_cfg_info_t_desc_count_set(ifcs_ring_cfg_info_t *ring_cfg_info_p, ifcs_uint32_t desc_count);

/**
 * @brief Get the ring_cfg_info structure with desc_count
 *
 * @param [in,out] ring_cfg_info_p - ring_cfg_info
 * @param [in]     desc_count_p    - desc_count
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ring_cfg_info_t_desc_count_get(ifcs_ring_cfg_info_t *ring_cfg_info_p, ifcs_uint32_t *desc_count_p);

/**
 * @brief Set the ring_cfg_info structure with priority
 *
 * @param [in,out] ring_cfg_info_p - ring_cfg_info
 * @param [in]     priority        - priority
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ring_cfg_info_t_priority_set(ifcs_ring_cfg_info_t *ring_cfg_info_p, ifcs_uint8_t priority);

/**
 * @brief Get the ring_cfg_info structure with priority
 *
 * @param [in,out] ring_cfg_info_p - ring_cfg_info
 * @param [in]     priority_p      - priority
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ring_cfg_info_t_priority_get(ifcs_ring_cfg_info_t *ring_cfg_info_p, ifcs_uint8_t *priority_p);

/**
 * @brief Set the ring_cfg_info structure with queues
 *
 * @param [in,out] ring_cfg_info_p - ring_cfg_info
 * @param [in]     queues_p        - queues
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ring_cfg_info_t_queues_set(ifcs_ring_cfg_info_t *ring_cfg_info_p, ifcs_cpu_queue_list_t *queues_p);

/**
 * @brief Get the ring_cfg_info structure with queues
 *
 * @param [in,out] ring_cfg_info_p - ring_cfg_info
 * @param [in]     queues_p        - queues
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ring_cfg_info_t_queues_get(ifcs_ring_cfg_info_t *ring_cfg_info_p, ifcs_cpu_queue_list_t *queues_p);

/**
 * @brief ACL drop action
 */
typedef struct ifcs_acl_drop_action_s {

    ifcs_acl_action_t green;                     ///< Drop green colored packets
    ifcs_acl_action_t yellow;                    ///< Drop Yellow colored packets
    ifcs_acl_action_t red;                       ///< Drop Red colored packets
    ifcs_handle_t     pp_drop_reason;            ///< Packet processing drop reason handle
    ifcs_uint8_t      _dirty_green : 1;          ///< indicates if user has set green
    ifcs_uint8_t      _dirty_yellow : 1;         ///< indicates if user has set yellow
    ifcs_uint8_t      _dirty_red : 1;            ///< indicates if user has set red
    ifcs_uint8_t      _dirty_pp_drop_reason : 1; ///< indicates if user has set pp_drop_reason
} ifcs_acl_drop_action_t;

/**
 * @brief Initialize the acl_drop_action structure
 *
 * @param [in,out] acl_drop_action_p - acl_drop_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_action_t_init(ifcs_acl_drop_action_t *acl_drop_action_p);
/**
 * @brief Set the acl_drop_action structure with green
 *
 * @param [in,out] acl_drop_action_p - acl_drop_action
 * @param [in]     green             - green
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_action_t_green_set(ifcs_acl_drop_action_t *acl_drop_action_p, ifcs_acl_action_t green);

/**
 * @brief Get the acl_drop_action structure with green
 *
 * @param [in,out] acl_drop_action_p - acl_drop_action
 * @param [in]     green_p           - green
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_action_t_green_get(ifcs_acl_drop_action_t *acl_drop_action_p, ifcs_acl_action_t *green_p);

/**
 * @brief Set the acl_drop_action structure with yellow
 *
 * @param [in,out] acl_drop_action_p - acl_drop_action
 * @param [in]     yellow            - yellow
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_action_t_yellow_set(ifcs_acl_drop_action_t *acl_drop_action_p, ifcs_acl_action_t yellow);

/**
 * @brief Get the acl_drop_action structure with yellow
 *
 * @param [in,out] acl_drop_action_p - acl_drop_action
 * @param [in]     yellow_p          - yellow
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_action_t_yellow_get(ifcs_acl_drop_action_t *acl_drop_action_p, ifcs_acl_action_t *yellow_p);

/**
 * @brief Set the acl_drop_action structure with red
 *
 * @param [in,out] acl_drop_action_p - acl_drop_action
 * @param [in]     red               - red
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_action_t_red_set(ifcs_acl_drop_action_t *acl_drop_action_p, ifcs_acl_action_t red);

/**
 * @brief Get the acl_drop_action structure with red
 *
 * @param [in,out] acl_drop_action_p - acl_drop_action
 * @param [in]     red_p             - red
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_action_t_red_get(ifcs_acl_drop_action_t *acl_drop_action_p, ifcs_acl_action_t *red_p);

/**
 * @brief Set the acl_drop_action structure with pp_drop_reason
 *
 * @param [in,out] acl_drop_action_p - acl_drop_action
 * @param [in]     pp_drop_reason    - pp_drop_reason
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_action_t_pp_drop_reason_set(ifcs_acl_drop_action_t *acl_drop_action_p, ifcs_handle_t pp_drop_reason);

/**
 * @brief Get the acl_drop_action structure with pp_drop_reason
 *
 * @param [in,out] acl_drop_action_p - acl_drop_action
 * @param [in]     pp_drop_reason_p  - pp_drop_reason
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_action_t_pp_drop_reason_get(ifcs_acl_drop_action_t *acl_drop_action_p, ifcs_handle_t *pp_drop_reason_p);

/**
 * @brief ACL drop override action
 */
typedef struct ifcs_acl_drop_override_action_s {

    ifcs_acl_action_t green;             ///< Cancel Drop Decision On green colored packets
    ifcs_acl_action_t yellow;            ///< Cancel Drop Decision On Yellow colored packets
    ifcs_acl_action_t red;               ///< Cancel Drop Decision On Red colored packets
    ifcs_uint8_t      _dirty_green : 1;  ///< indicates if user has set green
    ifcs_uint8_t      _dirty_yellow : 1; ///< indicates if user has set yellow
    ifcs_uint8_t      _dirty_red : 1;    ///< indicates if user has set red
} ifcs_acl_drop_override_action_t;

/**
 * @brief Initialize the acl_drop_override_action structure
 *
 * @param [in,out] acl_drop_override_action_p - acl_drop_override_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_override_action_t_init(ifcs_acl_drop_override_action_t *acl_drop_override_action_p);
/**
 * @brief Set the acl_drop_override_action structure with green
 *
 * @param [in,out] acl_drop_override_action_p - acl_drop_override_action
 * @param [in]     green                      - green
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_override_action_t_green_set(ifcs_acl_drop_override_action_t *acl_drop_override_action_p, ifcs_acl_action_t green);

/**
 * @brief Get the acl_drop_override_action structure with green
 *
 * @param [in,out] acl_drop_override_action_p - acl_drop_override_action
 * @param [in]     green_p                    - green
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_override_action_t_green_get(ifcs_acl_drop_override_action_t *acl_drop_override_action_p, ifcs_acl_action_t *green_p);

/**
 * @brief Set the acl_drop_override_action structure with yellow
 *
 * @param [in,out] acl_drop_override_action_p - acl_drop_override_action
 * @param [in]     yellow                     - yellow
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_override_action_t_yellow_set(ifcs_acl_drop_override_action_t *acl_drop_override_action_p, ifcs_acl_action_t yellow);

/**
 * @brief Get the acl_drop_override_action structure with yellow
 *
 * @param [in,out] acl_drop_override_action_p - acl_drop_override_action
 * @param [in]     yellow_p                   - yellow
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_override_action_t_yellow_get(ifcs_acl_drop_override_action_t *acl_drop_override_action_p, ifcs_acl_action_t *yellow_p);

/**
 * @brief Set the acl_drop_override_action structure with red
 *
 * @param [in,out] acl_drop_override_action_p - acl_drop_override_action
 * @param [in]     red                        - red
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_override_action_t_red_set(ifcs_acl_drop_override_action_t *acl_drop_override_action_p, ifcs_acl_action_t red);

/**
 * @brief Get the acl_drop_override_action structure with red
 *
 * @param [in,out] acl_drop_override_action_p - acl_drop_override_action
 * @param [in]     red_p                      - red
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_drop_override_action_t_red_get(ifcs_acl_drop_override_action_t *acl_drop_override_action_p, ifcs_acl_action_t *red_p);

/**
 * @brief ACL Copy to CPU action
 */
typedef struct ifcs_acl_ctc_action_s {

    ifcs_handle_t     hostif;            ///< The Hostif handle
    ifcs_acl_action_t green;             ///< CTC on green colored packets
    ifcs_acl_action_t yellow;            ///< CTC on Yellow colored packets
    ifcs_acl_action_t red;               ///< CTC on  Red colored packets
    ifcs_uint8_t      _dirty_hostif : 1; ///< indicates if user has set hostif
    ifcs_uint8_t      _dirty_green : 1;  ///< indicates if user has set green
    ifcs_uint8_t      _dirty_yellow : 1; ///< indicates if user has set yellow
    ifcs_uint8_t      _dirty_red : 1;    ///< indicates if user has set red
} ifcs_acl_ctc_action_t;

/**
 * @brief Initialize the acl_ctc_action structure
 *
 * @param [in,out] acl_ctc_action_p - acl_ctc_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_action_t_init(ifcs_acl_ctc_action_t *acl_ctc_action_p);
/**
 * @brief Set the acl_ctc_action structure with hostif
 *
 * @param [in,out] acl_ctc_action_p - acl_ctc_action
 * @param [in]     hostif           - hostif
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_action_t_hostif_set(ifcs_acl_ctc_action_t *acl_ctc_action_p, ifcs_handle_t hostif);

/**
 * @brief Get the acl_ctc_action structure with hostif
 *
 * @param [in,out] acl_ctc_action_p - acl_ctc_action
 * @param [in]     hostif_p         - hostif
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_action_t_hostif_get(ifcs_acl_ctc_action_t *acl_ctc_action_p, ifcs_handle_t *hostif_p);

/**
 * @brief Set the acl_ctc_action structure with green
 *
 * @param [in,out] acl_ctc_action_p - acl_ctc_action
 * @param [in]     green            - green
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_action_t_green_set(ifcs_acl_ctc_action_t *acl_ctc_action_p, ifcs_acl_action_t green);

/**
 * @brief Get the acl_ctc_action structure with green
 *
 * @param [in,out] acl_ctc_action_p - acl_ctc_action
 * @param [in]     green_p          - green
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_action_t_green_get(ifcs_acl_ctc_action_t *acl_ctc_action_p, ifcs_acl_action_t *green_p);

/**
 * @brief Set the acl_ctc_action structure with yellow
 *
 * @param [in,out] acl_ctc_action_p - acl_ctc_action
 * @param [in]     yellow           - yellow
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_action_t_yellow_set(ifcs_acl_ctc_action_t *acl_ctc_action_p, ifcs_acl_action_t yellow);

/**
 * @brief Get the acl_ctc_action structure with yellow
 *
 * @param [in,out] acl_ctc_action_p - acl_ctc_action
 * @param [in]     yellow_p         - yellow
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_action_t_yellow_get(ifcs_acl_ctc_action_t *acl_ctc_action_p, ifcs_acl_action_t *yellow_p);

/**
 * @brief Set the acl_ctc_action structure with red
 *
 * @param [in,out] acl_ctc_action_p - acl_ctc_action
 * @param [in]     red              - red
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_action_t_red_set(ifcs_acl_ctc_action_t *acl_ctc_action_p, ifcs_acl_action_t red);

/**
 * @brief Get the acl_ctc_action structure with red
 *
 * @param [in,out] acl_ctc_action_p - acl_ctc_action
 * @param [in]     red_p            - red
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_action_t_red_get(ifcs_acl_ctc_action_t *acl_ctc_action_p, ifcs_acl_action_t *red_p);

/**
 * @brief ACL Copy to CPU cancel action
 */
typedef struct ifcs_acl_ctc_override_action_s {

    ifcs_acl_action_t green;             ///< Cancel CTC on green colored packets
    ifcs_acl_action_t yellow;            ///< Cancel CTC on Yellow colored packets
    ifcs_acl_action_t red;               ///< Cancel CTC on  Red colored packets
    ifcs_uint8_t      _dirty_green : 1;  ///< indicates if user has set green
    ifcs_uint8_t      _dirty_yellow : 1; ///< indicates if user has set yellow
    ifcs_uint8_t      _dirty_red : 1;    ///< indicates if user has set red
} ifcs_acl_ctc_override_action_t;

/**
 * @brief Initialize the acl_ctc_override_action structure
 *
 * @param [in,out] acl_ctc_override_action_p - acl_ctc_override_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_override_action_t_init(ifcs_acl_ctc_override_action_t *acl_ctc_override_action_p);
/**
 * @brief Set the acl_ctc_override_action structure with green
 *
 * @param [in,out] acl_ctc_override_action_p - acl_ctc_override_action
 * @param [in]     green                     - green
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_override_action_t_green_set(ifcs_acl_ctc_override_action_t *acl_ctc_override_action_p, ifcs_acl_action_t green);

/**
 * @brief Get the acl_ctc_override_action structure with green
 *
 * @param [in,out] acl_ctc_override_action_p - acl_ctc_override_action
 * @param [in]     green_p                   - green
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_override_action_t_green_get(ifcs_acl_ctc_override_action_t *acl_ctc_override_action_p, ifcs_acl_action_t *green_p);

/**
 * @brief Set the acl_ctc_override_action structure with yellow
 *
 * @param [in,out] acl_ctc_override_action_p - acl_ctc_override_action
 * @param [in]     yellow                    - yellow
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_override_action_t_yellow_set(ifcs_acl_ctc_override_action_t *acl_ctc_override_action_p, ifcs_acl_action_t yellow);

/**
 * @brief Get the acl_ctc_override_action structure with yellow
 *
 * @param [in,out] acl_ctc_override_action_p - acl_ctc_override_action
 * @param [in]     yellow_p                  - yellow
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_override_action_t_yellow_get(ifcs_acl_ctc_override_action_t *acl_ctc_override_action_p, ifcs_acl_action_t *yellow_p);

/**
 * @brief Set the acl_ctc_override_action structure with red
 *
 * @param [in,out] acl_ctc_override_action_p - acl_ctc_override_action
 * @param [in]     red                       - red
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_override_action_t_red_set(ifcs_acl_ctc_override_action_t *acl_ctc_override_action_p, ifcs_acl_action_t red);

/**
 * @brief Get the acl_ctc_override_action structure with red
 *
 * @param [in,out] acl_ctc_override_action_p - acl_ctc_override_action
 * @param [in]     red_p                     - red
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ctc_override_action_t_red_get(ifcs_acl_ctc_override_action_t *acl_ctc_override_action_p, ifcs_acl_action_t *red_p);

/**
 * @brief ACL queue action for port
 */
typedef struct ifcs_acl_queue_action_s {

    ifcs_acl_action_t green;                    ///< Enable for green color packets
    uint32_t          green_offset;             ///< New queue number for green color packets
    ifcs_acl_action_t yellow;                   ///< Enable for yellow color packets
    uint32_t          yellow_offset;            ///< New queue number for yellow color packets
    ifcs_acl_action_t red;                      ///< Enable for red color packets
    uint32_t          red_offset;               ///< New queue number for red color packets
    ifcs_uint8_t      _dirty_green : 1;         ///< indicates if user has set green
    ifcs_uint8_t      _dirty_green_offset : 1;  ///< indicates if user has set green_offset
    ifcs_uint8_t      _dirty_yellow : 1;        ///< indicates if user has set yellow
    ifcs_uint8_t      _dirty_yellow_offset : 1; ///< indicates if user has set yellow_offset
    ifcs_uint8_t      _dirty_red : 1;           ///< indicates if user has set red
    ifcs_uint8_t      _dirty_red_offset : 1;    ///< indicates if user has set red_offset
} ifcs_acl_queue_action_t;

/**
 * @brief Initialize the acl_queue_action structure
 *
 * @param [in,out] acl_queue_action_p - acl_queue_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_queue_action_t_init(ifcs_acl_queue_action_t *acl_queue_action_p);
/**
 * @brief Set the acl_queue_action structure with green
 *
 * @param [in,out] acl_queue_action_p - acl_queue_action
 * @param [in]     green              - green
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_queue_action_t_green_set(ifcs_acl_queue_action_t *acl_queue_action_p, ifcs_acl_action_t green);

/**
 * @brief Get the acl_queue_action structure with green
 *
 * @param [in,out] acl_queue_action_p - acl_queue_action
 * @param [in]     green_p            - green
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_queue_action_t_green_get(ifcs_acl_queue_action_t *acl_queue_action_p, ifcs_acl_action_t *green_p);

/**
 * @brief Set the acl_queue_action structure with yellow
 *
 * @param [in,out] acl_queue_action_p - acl_queue_action
 * @param [in]     yellow             - yellow
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_queue_action_t_yellow_set(ifcs_acl_queue_action_t *acl_queue_action_p, ifcs_acl_action_t yellow);

/**
 * @brief Get the acl_queue_action structure with yellow
 *
 * @param [in,out] acl_queue_action_p - acl_queue_action
 * @param [in]     yellow_p           - yellow
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_queue_action_t_yellow_get(ifcs_acl_queue_action_t *acl_queue_action_p, ifcs_acl_action_t *yellow_p);

/**
 * @brief Set the acl_queue_action structure with red
 *
 * @param [in,out] acl_queue_action_p - acl_queue_action
 * @param [in]     red                - red
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_queue_action_t_red_set(ifcs_acl_queue_action_t *acl_queue_action_p, ifcs_acl_action_t red);

/**
 * @brief Get the acl_queue_action structure with red
 *
 * @param [in,out] acl_queue_action_p - acl_queue_action
 * @param [in]     red_p              - red
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_queue_action_t_red_get(ifcs_acl_queue_action_t *acl_queue_action_p, ifcs_acl_action_t *red_p);

/**
 * @brief ACL CPU queue action for CPU port
 */
typedef struct ifcs_acl_cpu_queue_action_s {

    ifcs_acl_action_t enable;            ///< Enable cpu queue action
    uint32_t          offset;            ///< New queue number
    ifcs_uint8_t      _dirty_enable : 1; ///< indicates if user has set enable
    ifcs_uint8_t      _dirty_offset : 1; ///< indicates if user has set offset
} ifcs_acl_cpu_queue_action_t;

/**
 * @brief Initialize the acl_cpu_queue_action structure
 *
 * @param [in,out] acl_cpu_queue_action_p - acl_cpu_queue_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_cpu_queue_action_t_init(ifcs_acl_cpu_queue_action_t *acl_cpu_queue_action_p);
/**
 * @brief Set the acl_cpu_queue_action structure with enable
 *
 * @param [in,out] acl_cpu_queue_action_p - acl_cpu_queue_action
 * @param [in]     enable                 - enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_cpu_queue_action_t_enable_set(ifcs_acl_cpu_queue_action_t *acl_cpu_queue_action_p, ifcs_acl_action_t enable);

/**
 * @brief Get the acl_cpu_queue_action structure with enable
 *
 * @param [in,out] acl_cpu_queue_action_p - acl_cpu_queue_action
 * @param [in]     enable_p               - enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_cpu_queue_action_t_enable_get(ifcs_acl_cpu_queue_action_t *acl_cpu_queue_action_p, ifcs_acl_action_t *enable_p);

/**
 * @brief ACL QOS action
 */
typedef struct ifcs_acl_qos_action_s {

    uint32_t     green_update_type;                 ///< Update type for green colored packets (refer ifcs_acl_qos_update_type_t)
    uint32_t     green_update_tag_type;             ///< Tag to be updated (refer ifcs_vlan_map_tag_type_t)
    uint32_t     green_value;                       ///< New QOS value for green colored packets
    uint32_t     yellow_update_type;                ///< Update type for yellow colored packets (refer ifcs_acl_qos_update_type_t)
    uint32_t     yellow_update_tag_type;            ///< Tag to be updated (refer ifcs_vlan_map_tag_type_t)
    uint32_t     yellow_value;                      ///< New QOS value for yellow colored packets
    uint32_t     red_update_type;                   ///< Update type for red colored packets (refer ifcs_acl_qos_update_type_t)
    uint32_t     red_update_tag_type;               ///< Tag to be updated (refer ifcs_vlan_map_tag_type_t)
    uint32_t     red_value;                         ///< New QOS value for red colored packets
    ifcs_uint8_t _dirty_green_update_type : 1;      ///< indicates if user has set green_update_type
    ifcs_uint8_t _dirty_green_update_tag_type : 1;  ///< indicates if user has set green_update_tag_type
    ifcs_uint8_t _dirty_green_value : 1;            ///< indicates if user has set green_value
    ifcs_uint8_t _dirty_yellow_update_type : 1;     ///< indicates if user has set yellow_update_type
    ifcs_uint8_t _dirty_yellow_update_tag_type : 1; ///< indicates if user has set yellow_update_tag_type
    ifcs_uint8_t _dirty_yellow_value : 1;           ///< indicates if user has set yellow_value
    ifcs_uint8_t _dirty_red_update_type : 1;        ///< indicates if user has set red_update_type
    ifcs_uint8_t _dirty_red_update_tag_type : 1;    ///< indicates if user has set red_update_tag_type
    ifcs_uint8_t _dirty_red_value : 1;              ///< indicates if user has set red_value
} ifcs_acl_qos_action_t;

/**
 * @brief Initialize the acl_qos_action structure
 *
 * @param [in,out] acl_qos_action_p - acl_qos_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_qos_action_t_init(ifcs_acl_qos_action_t *acl_qos_action_p);

/**
 * @brief ACL Set TC action
 */
typedef struct ifcs_acl_set_tc_action_s {

    ifcs_acl_action_t green;                   ///< Enable for green color packets
    uint32_t          green_value;             ///< New TC value for green color packets
    ifcs_acl_action_t yellow;                  ///< Enable for yellow color packets
    uint32_t          yellow_value;            ///< New TC value for yellow color packets
    ifcs_acl_action_t red;                     ///< Enable for red color packets
    uint32_t          red_value;               ///< New TC value for red color packets
    ifcs_uint8_t      _dirty_green : 1;        ///< indicates if user has set green
    ifcs_uint8_t      _dirty_green_value : 1;  ///< indicates if user has set green_value
    ifcs_uint8_t      _dirty_yellow : 1;       ///< indicates if user has set yellow
    ifcs_uint8_t      _dirty_yellow_value : 1; ///< indicates if user has set yellow_value
    ifcs_uint8_t      _dirty_red : 1;          ///< indicates if user has set red
    ifcs_uint8_t      _dirty_red_value : 1;    ///< indicates if user has set red_value
} ifcs_acl_set_tc_action_t;

/**
 * @brief Initialize the acl_set_tc_action structure
 *
 * @param [in,out] acl_set_tc_action_p - acl_set_tc_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_tc_action_t_init(ifcs_acl_set_tc_action_t *acl_set_tc_action_p);
/**
 * @brief Set the acl_set_tc_action structure with green
 *
 * @param [in,out] acl_set_tc_action_p - acl_set_tc_action
 * @param [in]     green               - green
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_tc_action_t_green_set(ifcs_acl_set_tc_action_t *acl_set_tc_action_p, ifcs_acl_action_t green);

/**
 * @brief Get the acl_set_tc_action structure with green
 *
 * @param [in,out] acl_set_tc_action_p - acl_set_tc_action
 * @param [in]     green_p             - green
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_tc_action_t_green_get(ifcs_acl_set_tc_action_t *acl_set_tc_action_p, ifcs_acl_action_t *green_p);

/**
 * @brief Set the acl_set_tc_action structure with yellow
 *
 * @param [in,out] acl_set_tc_action_p - acl_set_tc_action
 * @param [in]     yellow              - yellow
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_tc_action_t_yellow_set(ifcs_acl_set_tc_action_t *acl_set_tc_action_p, ifcs_acl_action_t yellow);

/**
 * @brief Get the acl_set_tc_action structure with yellow
 *
 * @param [in,out] acl_set_tc_action_p - acl_set_tc_action
 * @param [in]     yellow_p            - yellow
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_tc_action_t_yellow_get(ifcs_acl_set_tc_action_t *acl_set_tc_action_p, ifcs_acl_action_t *yellow_p);

/**
 * @brief Set the acl_set_tc_action structure with red
 *
 * @param [in,out] acl_set_tc_action_p - acl_set_tc_action
 * @param [in]     red                 - red
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_tc_action_t_red_set(ifcs_acl_set_tc_action_t *acl_set_tc_action_p, ifcs_acl_action_t red);

/**
 * @brief Get the acl_set_tc_action structure with red
 *
 * @param [in,out] acl_set_tc_action_p - acl_set_tc_action
 * @param [in]     red_p               - red
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_tc_action_t_red_get(ifcs_acl_set_tc_action_t *acl_set_tc_action_p, ifcs_acl_action_t *red_p);

/**
 * @brief ACL Set DP action
 */
typedef struct ifcs_acl_set_dp_action_s {

    ifcs_acl_action_t green;                   ///< Enable for green color packets
    uint32_t          green_value;             ///< New Packet Color value for green color packets
    ifcs_acl_action_t yellow;                  ///< Enable for yellow color packets
    uint32_t          yellow_value;            ///< New Packet Color value for yellow color packets
    ifcs_acl_action_t red;                     ///< Enable for red color packets
    uint32_t          red_value;               ///< New Packet Color value for red color packets
    ifcs_uint8_t      _dirty_green : 1;        ///< indicates if user has set green
    ifcs_uint8_t      _dirty_green_value : 1;  ///< indicates if user has set green_value
    ifcs_uint8_t      _dirty_yellow : 1;       ///< indicates if user has set yellow
    ifcs_uint8_t      _dirty_yellow_value : 1; ///< indicates if user has set yellow_value
    ifcs_uint8_t      _dirty_red : 1;          ///< indicates if user has set red
    ifcs_uint8_t      _dirty_red_value : 1;    ///< indicates if user has set red_value
} ifcs_acl_set_dp_action_t;

/**
 * @brief Initialize the acl_set_dp_action structure
 *
 * @param [in,out] acl_set_dp_action_p - acl_set_dp_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_dp_action_t_init(ifcs_acl_set_dp_action_t *acl_set_dp_action_p);
/**
 * @brief Set the acl_set_dp_action structure with green
 *
 * @param [in,out] acl_set_dp_action_p - acl_set_dp_action
 * @param [in]     green               - green
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_dp_action_t_green_set(ifcs_acl_set_dp_action_t *acl_set_dp_action_p, ifcs_acl_action_t green);

/**
 * @brief Get the acl_set_dp_action structure with green
 *
 * @param [in,out] acl_set_dp_action_p - acl_set_dp_action
 * @param [in]     green_p             - green
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_dp_action_t_green_get(ifcs_acl_set_dp_action_t *acl_set_dp_action_p, ifcs_acl_action_t *green_p);

/**
 * @brief Set the acl_set_dp_action structure with yellow
 *
 * @param [in,out] acl_set_dp_action_p - acl_set_dp_action
 * @param [in]     yellow              - yellow
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_dp_action_t_yellow_set(ifcs_acl_set_dp_action_t *acl_set_dp_action_p, ifcs_acl_action_t yellow);

/**
 * @brief Get the acl_set_dp_action structure with yellow
 *
 * @param [in,out] acl_set_dp_action_p - acl_set_dp_action
 * @param [in]     yellow_p            - yellow
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_dp_action_t_yellow_get(ifcs_acl_set_dp_action_t *acl_set_dp_action_p, ifcs_acl_action_t *yellow_p);

/**
 * @brief Set the acl_set_dp_action structure with red
 *
 * @param [in,out] acl_set_dp_action_p - acl_set_dp_action
 * @param [in]     red                 - red
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_dp_action_t_red_set(ifcs_acl_set_dp_action_t *acl_set_dp_action_p, ifcs_acl_action_t red);

/**
 * @brief Get the acl_set_dp_action structure with red
 *
 * @param [in,out] acl_set_dp_action_p - acl_set_dp_action
 * @param [in]     red_p               - red
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_dp_action_t_red_get(ifcs_acl_set_dp_action_t *acl_set_dp_action_p, ifcs_acl_action_t *red_p);

/**
 * @brief ACL Set Packet ECN action
 */
typedef struct ifcs_acl_set_system_ecn_action_s {

    ifcs_acl_action_t green_assign_cr;              ///< Assign CR for green color packets
    uint32_t          green_cr;                     ///< CR value used when green_assign_cr is set
    ifcs_acl_action_t green_assign_ect;             ///< Assign ECT for green color packets
    uint32_t          green_ect;                    ///< ECT value used when green_assign_ect is set
    ifcs_acl_action_t green_assign_ce;              ///< Assign CE for green color packets
    uint32_t          green_ce;                     ///< CE value used when green_assign_ce is set
    ifcs_acl_action_t yellow_assign_cr;             ///< Assign CR for yellow color packets
    uint32_t          yellow_cr;                    ///< CR value used when yellow_assign_cr is set
    ifcs_acl_action_t yellow_assign_ect;            ///< Assign ECT for yellow color packets
    uint32_t          yellow_ect;                   ///< ECT value used when yellow_assign_ect is set
    ifcs_acl_action_t yellow_assign_ce;             ///< Assign CE for yellow color packets
    uint32_t          yellow_ce;                    ///< CE value used when yellow_assign_ce is set
    ifcs_acl_action_t red_assign_cr;                ///< Assign CR for red color packets
    uint32_t          red_cr;                       ///< CR value used when red_assign_cr is set
    ifcs_acl_action_t red_assign_ect;               ///< Assign ECT for red color packets
    uint32_t          red_ect;                      ///< ECT value used when red_assign_ect is set
    ifcs_acl_action_t red_assign_ce;                ///< Assign CE for red color packets
    uint32_t          red_ce;                       ///< CE value used when red_assign_ce is set
    ifcs_uint8_t      _dirty_green_assign_cr : 1;   ///< indicates if user has set green_assign_cr
    ifcs_uint8_t      _dirty_green_cr : 1;          ///< indicates if user has set green_cr
    ifcs_uint8_t      _dirty_green_assign_ect : 1;  ///< indicates if user has set green_assign_ect
    ifcs_uint8_t      _dirty_green_ect : 1;         ///< indicates if user has set green_ect
    ifcs_uint8_t      _dirty_green_assign_ce : 1;   ///< indicates if user has set green_assign_ce
    ifcs_uint8_t      _dirty_green_ce : 1;          ///< indicates if user has set green_ce
    ifcs_uint8_t      _dirty_yellow_assign_cr : 1;  ///< indicates if user has set yellow_assign_cr
    ifcs_uint8_t      _dirty_yellow_cr : 1;         ///< indicates if user has set yellow_cr
    ifcs_uint8_t      _dirty_yellow_assign_ect : 1; ///< indicates if user has set yellow_assign_ect
    ifcs_uint8_t      _dirty_yellow_ect : 1;        ///< indicates if user has set yellow_ect
    ifcs_uint8_t      _dirty_yellow_assign_ce : 1;  ///< indicates if user has set yellow_assign_ce
    ifcs_uint8_t      _dirty_yellow_ce : 1;         ///< indicates if user has set yellow_ce
    ifcs_uint8_t      _dirty_red_assign_cr : 1;     ///< indicates if user has set red_assign_cr
    ifcs_uint8_t      _dirty_red_cr : 1;            ///< indicates if user has set red_cr
    ifcs_uint8_t      _dirty_red_assign_ect : 1;    ///< indicates if user has set red_assign_ect
    ifcs_uint8_t      _dirty_red_ect : 1;           ///< indicates if user has set red_ect
    ifcs_uint8_t      _dirty_red_assign_ce : 1;     ///< indicates if user has set red_assign_ce
    ifcs_uint8_t      _dirty_red_ce : 1;            ///< indicates if user has set red_ce
} ifcs_acl_set_system_ecn_action_t;

/**
 * @brief Initialize the acl_set_system_ecn_action structure
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_init(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p);
/**
 * @brief Set the acl_set_system_ecn_action structure with green_assign_cr
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     green_assign_cr             - green_assign_cr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_green_assign_cr_set(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t green_assign_cr);

/**
 * @brief Get the acl_set_system_ecn_action structure with green_assign_cr
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     green_assign_cr_p           - green_assign_cr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_green_assign_cr_get(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t *green_assign_cr_p);

/**
 * @brief Set the acl_set_system_ecn_action structure with green_assign_ect
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     green_assign_ect            - green_assign_ect
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_green_assign_ect_set(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t green_assign_ect);

/**
 * @brief Get the acl_set_system_ecn_action structure with green_assign_ect
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     green_assign_ect_p          - green_assign_ect
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_green_assign_ect_get(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t *green_assign_ect_p);

/**
 * @brief Set the acl_set_system_ecn_action structure with green_assign_ce
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     green_assign_ce             - green_assign_ce
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_green_assign_ce_set(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t green_assign_ce);

/**
 * @brief Get the acl_set_system_ecn_action structure with green_assign_ce
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     green_assign_ce_p           - green_assign_ce
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_green_assign_ce_get(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t *green_assign_ce_p);

/**
 * @brief Set the acl_set_system_ecn_action structure with yellow_assign_cr
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     yellow_assign_cr            - yellow_assign_cr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_yellow_assign_cr_set(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t yellow_assign_cr);

/**
 * @brief Get the acl_set_system_ecn_action structure with yellow_assign_cr
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     yellow_assign_cr_p          - yellow_assign_cr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_yellow_assign_cr_get(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t *yellow_assign_cr_p);

/**
 * @brief Set the acl_set_system_ecn_action structure with yellow_assign_ect
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     yellow_assign_ect           - yellow_assign_ect
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_yellow_assign_ect_set(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t yellow_assign_ect);

/**
 * @brief Get the acl_set_system_ecn_action structure with yellow_assign_ect
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     yellow_assign_ect_p         - yellow_assign_ect
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_yellow_assign_ect_get(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t *yellow_assign_ect_p);

/**
 * @brief Set the acl_set_system_ecn_action structure with yellow_assign_ce
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     yellow_assign_ce            - yellow_assign_ce
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_yellow_assign_ce_set(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t yellow_assign_ce);

/**
 * @brief Get the acl_set_system_ecn_action structure with yellow_assign_ce
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     yellow_assign_ce_p          - yellow_assign_ce
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_yellow_assign_ce_get(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t *yellow_assign_ce_p);

/**
 * @brief Set the acl_set_system_ecn_action structure with red_assign_cr
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     red_assign_cr               - red_assign_cr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_red_assign_cr_set(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t red_assign_cr);

/**
 * @brief Get the acl_set_system_ecn_action structure with red_assign_cr
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     red_assign_cr_p             - red_assign_cr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_red_assign_cr_get(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t *red_assign_cr_p);

/**
 * @brief Set the acl_set_system_ecn_action structure with red_assign_ect
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     red_assign_ect              - red_assign_ect
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_red_assign_ect_set(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t red_assign_ect);

/**
 * @brief Get the acl_set_system_ecn_action structure with red_assign_ect
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     red_assign_ect_p            - red_assign_ect
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_red_assign_ect_get(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t *red_assign_ect_p);

/**
 * @brief Set the acl_set_system_ecn_action structure with red_assign_ce
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     red_assign_ce               - red_assign_ce
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_red_assign_ce_set(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t red_assign_ce);

/**
 * @brief Get the acl_set_system_ecn_action structure with red_assign_ce
 *
 * @param [in,out] acl_set_system_ecn_action_p - acl_set_system_ecn_action
 * @param [in]     red_assign_ce_p             - red_assign_ce
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_system_ecn_action_t_red_assign_ce_get(ifcs_acl_set_system_ecn_action_t *acl_set_system_ecn_action_p, ifcs_acl_action_t *red_assign_ce_p);

/**
 * @brief ACL Set DSCP  action
 */
typedef struct ifcs_acl_set_dscp_action_s {

    ifcs_ip_addr_family_t addr_family;            ///< Set DSCP Address Family (use this with acl_set_dscp action)
    uint32_t              value;                  ///< Set DSCP (use this with acl_set_dscp action)
    ifcs_uint8_t          _dirty_addr_family : 1; ///< indicates if user has set addr_family
    ifcs_uint8_t          _dirty_value : 1;       ///< indicates if user has set value
} ifcs_acl_set_dscp_action_t;

/**
 * @brief Initialize the acl_set_dscp_action structure
 *
 * @param [in,out] acl_set_dscp_action_p - acl_set_dscp_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_dscp_action_t_init(ifcs_acl_set_dscp_action_t *acl_set_dscp_action_p);
/**
 * @brief Set the acl_set_dscp_action structure with addr_family
 *
 * @param [in,out] acl_set_dscp_action_p - acl_set_dscp_action
 * @param [in]     addr_family           - addr_family
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_dscp_action_t_addr_family_set(ifcs_acl_set_dscp_action_t *acl_set_dscp_action_p, ifcs_ip_addr_family_t addr_family);

/**
 * @brief Get the acl_set_dscp_action structure with addr_family
 *
 * @param [in,out] acl_set_dscp_action_p - acl_set_dscp_action
 * @param [in]     addr_family_p         - addr_family
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_dscp_action_t_addr_family_get(ifcs_acl_set_dscp_action_t *acl_set_dscp_action_p, ifcs_ip_addr_family_t *addr_family_p);

/**
 * @brief ACL Set Vlan  action
 */
typedef struct ifcs_acl_set_vlan_action_s {

    uint16_t     vlan_id;            ///< set Vlan ID (use this with set_vlan_id action)
    uint8_t      dot1p;              ///< set user priority and cfi value(use this with set_vlan_priority_cfi action)
    ifcs_uint8_t _dirty_vlan_id : 1; ///< indicates if user has set vlan_id
    ifcs_uint8_t _dirty_dot1p : 1;   ///< indicates if user has set dot1p
} ifcs_acl_set_vlan_action_t;

/**
 * @brief Initialize the acl_set_vlan_action structure
 *
 * @param [in,out] acl_set_vlan_action_p - acl_set_vlan_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_vlan_action_t_init(ifcs_acl_set_vlan_action_t *acl_set_vlan_action_p);

/**
 * @brief ACL Set Priority Set Id  action
 */
typedef struct ifcs_acl_set_ps_id_action_s {

    ifcs_acl_action_t enable;            ///< Enable set ps_id action
    uint8_t           ps_id;             ///< ps_id (priority set (0-3))
    ifcs_uint8_t      _dirty_enable : 1; ///< indicates if user has set enable
    ifcs_uint8_t      _dirty_ps_id : 1;  ///< indicates if user has set ps_id
} ifcs_acl_set_ps_id_action_t;

/**
 * @brief Initialize the acl_set_ps_id_action structure
 *
 * @param [in,out] acl_set_ps_id_action_p - acl_set_ps_id_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_ps_id_action_t_init(ifcs_acl_set_ps_id_action_t *acl_set_ps_id_action_p);
/**
 * @brief Set the acl_set_ps_id_action structure with enable
 *
 * @param [in,out] acl_set_ps_id_action_p - acl_set_ps_id_action
 * @param [in]     enable                 - enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_ps_id_action_t_enable_set(ifcs_acl_set_ps_id_action_t *acl_set_ps_id_action_p, ifcs_acl_action_t enable);

/**
 * @brief Get the acl_set_ps_id_action structure with enable
 *
 * @param [in,out] acl_set_ps_id_action_p - acl_set_ps_id_action
 * @param [in]     enable_p               - enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_set_ps_id_action_t_enable_get(ifcs_acl_set_ps_id_action_t *acl_set_ps_id_action_p, ifcs_acl_action_t *enable_p);

/**
 * @brief ACL Set User Counter action
 */
typedef struct ifcs_acl_user_counter_action_s {

    ifcs_handle_t      bank_handle;            ///< set Flex stats bank handle
    ifcs_flex_op_cmd_t op_cmd;                 ///< set flex stats cmd (refer ifcs_flex_op_cmd_t)
    uint32_t           offset;                 ///< set flex stats index offset. For L2vni use ifcs_l2vni_flex_offset_t
    ifcs_uint8_t       _dirty_bank_handle : 1; ///< indicates if user has set bank_handle
    ifcs_uint8_t       _dirty_op_cmd : 1;      ///< indicates if user has set op_cmd
    ifcs_uint8_t       _dirty_offset : 1;      ///< indicates if user has set offset
} ifcs_acl_user_counter_action_t;

/**
 * @brief Initialize the acl_user_counter_action structure
 *
 * @param [in,out] acl_user_counter_action_p - acl_user_counter_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_user_counter_action_t_init(ifcs_acl_user_counter_action_t *acl_user_counter_action_p);
/**
 * @brief Set the acl_user_counter_action structure with bank_handle
 *
 * @param [in,out] acl_user_counter_action_p - acl_user_counter_action
 * @param [in]     bank_handle               - bank_handle
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_user_counter_action_t_bank_handle_set(ifcs_acl_user_counter_action_t *acl_user_counter_action_p, ifcs_handle_t bank_handle);

/**
 * @brief Get the acl_user_counter_action structure with bank_handle
 *
 * @param [in,out] acl_user_counter_action_p - acl_user_counter_action
 * @param [in]     bank_handle_p             - bank_handle
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_user_counter_action_t_bank_handle_get(ifcs_acl_user_counter_action_t *acl_user_counter_action_p, ifcs_handle_t *bank_handle_p);

/**
 * @brief Set the acl_user_counter_action structure with op_cmd
 *
 * @param [in,out] acl_user_counter_action_p - acl_user_counter_action
 * @param [in]     op_cmd                    - op_cmd
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_user_counter_action_t_op_cmd_set(ifcs_acl_user_counter_action_t *acl_user_counter_action_p, ifcs_flex_op_cmd_t op_cmd);

/**
 * @brief Get the acl_user_counter_action structure with op_cmd
 *
 * @param [in,out] acl_user_counter_action_p - acl_user_counter_action
 * @param [in]     op_cmd_p                  - op_cmd
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_user_counter_action_t_op_cmd_get(ifcs_acl_user_counter_action_t *acl_user_counter_action_p, ifcs_flex_op_cmd_t *op_cmd_p);

/**
 * @brief ACL Action for MAC Learn Override
 */
typedef struct ifcs_acl_learn_override_action_s {

    ifcs_acl_action_t enable;            ///< Enable learn override action
    ifcs_uint8_t      _dirty_enable : 1; ///< indicates if user has set enable
} ifcs_acl_learn_override_action_t;

/**
 * @brief Initialize the acl_learn_override_action structure
 *
 * @param [in,out] acl_learn_override_action_p - acl_learn_override_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_learn_override_action_t_init(ifcs_acl_learn_override_action_t *acl_learn_override_action_p);
/**
 * @brief Set the acl_learn_override_action structure with enable
 *
 * @param [in,out] acl_learn_override_action_p - acl_learn_override_action
 * @param [in]     enable                      - enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_learn_override_action_t_enable_set(ifcs_acl_learn_override_action_t *acl_learn_override_action_p, ifcs_acl_action_t enable);

/**
 * @brief Get the acl_learn_override_action structure with enable
 *
 * @param [in,out] acl_learn_override_action_p - acl_learn_override_action
 * @param [in]     enable_p                    - enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_learn_override_action_t_enable_get(ifcs_acl_learn_override_action_t *acl_learn_override_action_p, ifcs_acl_action_t *enable_p);

/**
 * @brief ACL Action for SFLOW Override
 */
typedef struct ifcs_acl_sflow_override_action_s {

    ifcs_acl_action_t enable;            ///< Enable sflow override action
    ifcs_uint8_t      _dirty_enable : 1; ///< indicates if user has set enable
} ifcs_acl_sflow_override_action_t;

/**
 * @brief Initialize the acl_sflow_override_action structure
 *
 * @param [in,out] acl_sflow_override_action_p - acl_sflow_override_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_sflow_override_action_t_init(ifcs_acl_sflow_override_action_t *acl_sflow_override_action_p);
/**
 * @brief Set the acl_sflow_override_action structure with enable
 *
 * @param [in,out] acl_sflow_override_action_p - acl_sflow_override_action
 * @param [in]     enable                      - enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_sflow_override_action_t_enable_set(ifcs_acl_sflow_override_action_t *acl_sflow_override_action_p, ifcs_acl_action_t enable);

/**
 * @brief Get the acl_sflow_override_action structure with enable
 *
 * @param [in,out] acl_sflow_override_action_p - acl_sflow_override_action
 * @param [in]     enable_p                    - enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_sflow_override_action_t_enable_get(ifcs_acl_sflow_override_action_t *acl_sflow_override_action_p, ifcs_acl_action_t *enable_p);

/**
 * @brief ACL Set Flow of Interest Action
 */
typedef struct ifcs_acl_flow_of_interest_action_s {

    ifcs_acl_action_t enable;            ///< Enable Flow of Interest action
    ifcs_uint8_t      _dirty_enable : 1; ///< indicates if user has set enable
} ifcs_acl_flow_of_interest_action_t;

/**
 * @brief Initialize the acl_flow_of_interest_action structure
 *
 * @param [in,out] acl_flow_of_interest_action_p - acl_flow_of_interest_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_flow_of_interest_action_t_init(ifcs_acl_flow_of_interest_action_t *acl_flow_of_interest_action_p);
/**
 * @brief Set the acl_flow_of_interest_action structure with enable
 *
 * @param [in,out] acl_flow_of_interest_action_p - acl_flow_of_interest_action
 * @param [in]     enable                        - enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_flow_of_interest_action_t_enable_set(ifcs_acl_flow_of_interest_action_t *acl_flow_of_interest_action_p, ifcs_acl_action_t enable);

/**
 * @brief Get the acl_flow_of_interest_action structure with enable
 *
 * @param [in,out] acl_flow_of_interest_action_p - acl_flow_of_interest_action
 * @param [in]     enable_p                      - enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_flow_of_interest_action_t_enable_get(ifcs_acl_flow_of_interest_action_t *acl_flow_of_interest_action_p, ifcs_acl_action_t *enable_p);

/**
 * @brief ACL override decrement TTL Action
 */
typedef struct ifcs_acl_ttl_decrement_override_action_s {

    ifcs_acl_action_t enable;            ///< Enable override decrement TTL action for both IPv4 and IPv6 packets
    ifcs_uint8_t      _dirty_enable : 1; ///< indicates if user has set enable
} ifcs_acl_ttl_decrement_override_action_t;

/**
 * @brief Initialize the acl_ttl_decrement_override_action structure
 *
 * @param [in,out] acl_ttl_decrement_override_action_p - acl_ttl_decrement_override_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ttl_decrement_override_action_t_init(ifcs_acl_ttl_decrement_override_action_t *acl_ttl_decrement_override_action_p);
/**
 * @brief Set the acl_ttl_decrement_override_action structure with enable
 *
 * @param [in,out] acl_ttl_decrement_override_action_p - acl_ttl_decrement_override_action
 * @param [in]     enable                              - enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ttl_decrement_override_action_t_enable_set(ifcs_acl_ttl_decrement_override_action_t *acl_ttl_decrement_override_action_p, ifcs_acl_action_t enable);

/**
 * @brief Get the acl_ttl_decrement_override_action structure with enable
 *
 * @param [in,out] acl_ttl_decrement_override_action_p - acl_ttl_decrement_override_action
 * @param [in]     enable_p                            - enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ttl_decrement_override_action_t_enable_get(ifcs_acl_ttl_decrement_override_action_t *acl_ttl_decrement_override_action_p, ifcs_acl_action_t *enable_p);

/**
 * @brief ACL Assign ACL Cookie to be matched in egress ACL (16 bits)
 */
typedef struct ifcs_acl_user_cookie_action_s {

    ifcs_acl_action_t enable;            ///< Enable Setting the acl cookie
    uint32_t          cookie;            ///< post Fwd ACL user Cookie
    ifcs_uint8_t      _dirty_enable : 1; ///< indicates if user has set enable
    ifcs_uint8_t      _dirty_cookie : 1; ///< indicates if user has set cookie
} ifcs_acl_user_cookie_action_t;

/**
 * @brief Initialize the acl_user_cookie_action structure
 *
 * @param [in,out] acl_user_cookie_action_p - acl_user_cookie_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_user_cookie_action_t_init(ifcs_acl_user_cookie_action_t *acl_user_cookie_action_p);
/**
 * @brief Set the acl_user_cookie_action structure with enable
 *
 * @param [in,out] acl_user_cookie_action_p - acl_user_cookie_action
 * @param [in]     enable                   - enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_user_cookie_action_t_enable_set(ifcs_acl_user_cookie_action_t *acl_user_cookie_action_p, ifcs_acl_action_t enable);

/**
 * @brief Get the acl_user_cookie_action structure with enable
 *
 * @param [in,out] acl_user_cookie_action_p - acl_user_cookie_action
 * @param [in]     enable_p                 - enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_user_cookie_action_t_enable_get(ifcs_acl_user_cookie_action_t *acl_user_cookie_action_p, ifcs_acl_action_t *enable_p);

/**
 * @brief ACL Assign L3IIF Action
 */
typedef struct ifcs_acl_post_fwd_acl_user_cookie_action_s {

    uint32_t     cookie;            ///< Post Fwd ACL user Cookie
    ifcs_uint8_t _dirty_cookie : 1; ///< indicates if user has set cookie
} ifcs_acl_post_fwd_acl_user_cookie_action_t;

/**
 * @brief Initialize the acl_post_fwd_acl_user_cookie_action structure
 *
 * @param [in,out] acl_post_fwd_acl_user_cookie_action_p - acl_post_fwd_acl_user_cookie_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_post_fwd_acl_user_cookie_action_t_init(ifcs_acl_post_fwd_acl_user_cookie_action_t *acl_post_fwd_acl_user_cookie_action_p);

/**
 * @brief ACL IPT Action on Flow of Interest
 */
typedef struct ifcs_acl_ipt_action_s {

    ifcs_acl_ipt_operation_t operation;                     ///< ACL IPT action clone/override-clone/no-op
    ifcs_handle_t            telemetry_instance;            ///< IPT telemetry instance
    ifcs_uint8_t             _dirty_operation : 1;          ///< indicates if user has set operation
    ifcs_uint8_t             _dirty_telemetry_instance : 1; ///< indicates if user has set telemetry_instance
} ifcs_acl_ipt_action_t;

/**
 * @brief Initialize the acl_ipt_action structure
 *
 * @param [in,out] acl_ipt_action_p     - acl_ipt_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ipt_action_t_init(ifcs_acl_ipt_action_t *acl_ipt_action_p);
/**
 * @brief Set the acl_ipt_action structure with operation
 *
 * @param [in,out] acl_ipt_action_p     - acl_ipt_action
 * @param [in]     operation            - operation
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ipt_action_t_operation_set(ifcs_acl_ipt_action_t *acl_ipt_action_p, ifcs_acl_ipt_operation_t operation);

/**
 * @brief Get the acl_ipt_action structure with operation
 *
 * @param [in,out] acl_ipt_action_p     - acl_ipt_action
 * @param [in]     operation_p          - operation
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ipt_action_t_operation_get(ifcs_acl_ipt_action_t *acl_ipt_action_p, ifcs_acl_ipt_operation_t *operation_p);

/**
 * @brief Set the acl_ipt_action structure with telemetry_instance
 *
 * @param [in,out] acl_ipt_action_p     - acl_ipt_action
 * @param [in]     telemetry_instance   - telemetry_instance
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ipt_action_t_telemetry_instance_set(ifcs_acl_ipt_action_t *acl_ipt_action_p, ifcs_handle_t telemetry_instance);

/**
 * @brief Get the acl_ipt_action structure with telemetry_instance
 *
 * @param [in,out] acl_ipt_action_p     - acl_ipt_action
 * @param [in]     telemetry_instance_p - telemetry_instance
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_acl_ipt_action_t_telemetry_instance_get(ifcs_acl_ipt_action_t *acl_ipt_action_p, ifcs_handle_t *telemetry_instance_p);

/**
 * @brief ACL Action (yellow and red fields are valid when ACE has a meter attached to it)
 */
typedef union ifcs_acl_action_value_u {

    ifcs_acl_drop_action_t                     drop;                     ///< Drop action
    ifcs_acl_drop_override_action_t            drop_override;            ///< Drop override action
    ifcs_acl_ctc_action_t                      ctc;                      ///< Ctc action
    ifcs_acl_ctc_override_action_t             ctc_override;             ///< Ctc override action
    ifcs_acl_queue_action_t                    queue;                    ///< Queue action
    ifcs_acl_cpu_queue_action_t                cpu_queue;                ///< CPU queue action
    ifcs_acl_qos_action_t                      qos;                      ///< Qos action
    ifcs_acl_set_tc_action_t                   set_tc;                   ///< Set Traffic Class action
    ifcs_acl_set_dp_action_t                   set_dp;                   ///< Set Packet Color action
    ifcs_acl_set_system_ecn_action_t           set_system_ecn;           ///< Set Packet ECN action
    ifcs_acl_set_dscp_action_t                 set_dscp;                 ///< Set Packet DSCP action
    ifcs_acl_set_vlan_action_t                 set_vlan;                 ///< Set VLAN attributes action
    ifcs_acl_user_counter_action_t             set_user_counter;         ///< Set VLAN attributes action
    ifcs_acl_set_ps_id_action_t                set_ps_id;                ///< Set PS ID action
    ifcs_acl_learn_override_action_t           learn_override;           ///< Mac Learn override action
    ifcs_acl_sflow_override_action_t           sflow_override;           ///< SFLOW override action
    ifcs_acl_flow_of_interest_action_t         flow_of_interest;         ///< Flow of Interest action
    ifcs_acl_ipt_action_t                      ipt;                      ///< IPT action on Flow of Interest
    ifcs_acl_ttl_decrement_override_action_t   ttl_decrement_override;   ///< Override decrement TTL action
    ifcs_acl_user_cookie_action_t              acl_user_cookie;          ///< Assign ACL User cookie in ingress ACL Table(post_fwd) that can be used in egress ACL table
    ifcs_acl_post_fwd_acl_user_cookie_action_t post_fwd_acl_user_cookie; ///< Assign Post Fwd Acl Cookie. Only Valid for PreFwd Stage ACL
} ifcs_acl_action_value_t;

/**
 * @brief Flex pool packet attribute map
 */
typedef struct ifcs_flex_stats_pkt_attr_map_s {

    ifcs_uint8_t attr_value;            ///< Attribute Value
    ifcs_bool_t  disable;               ///< Attribute to be disabled
    ifcs_uint8_t _dirty_attr_value : 1; ///< indicates if user has set attr_value
    ifcs_uint8_t _dirty_disable : 1;    ///< indicates if user has set disable
} ifcs_flex_stats_pkt_attr_map_t;

/**
 * @brief Initialize the flex_stats_pkt_attr_map structure
 *
 * @param [in,out] flex_stats_pkt_attr_map_p - flex_stats_pkt_attr_map
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_flex_stats_pkt_attr_map_t_init(ifcs_flex_stats_pkt_attr_map_t *flex_stats_pkt_attr_map_p);
/**
 * @brief Set the flex_stats_pkt_attr_map structure with attr_value
 *
 * @param [in,out] flex_stats_pkt_attr_map_p - flex_stats_pkt_attr_map
 * @param [in]     attr_value                - attr_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_flex_stats_pkt_attr_map_t_attr_value_set(ifcs_flex_stats_pkt_attr_map_t *flex_stats_pkt_attr_map_p, ifcs_uint8_t attr_value);

/**
 * @brief Get the flex_stats_pkt_attr_map structure with attr_value
 *
 * @param [in,out] flex_stats_pkt_attr_map_p - flex_stats_pkt_attr_map
 * @param [in]     attr_value_p              - attr_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_flex_stats_pkt_attr_map_t_attr_value_get(ifcs_flex_stats_pkt_attr_map_t *flex_stats_pkt_attr_map_p, ifcs_uint8_t *attr_value_p);

/**
 * @brief Set the flex_stats_pkt_attr_map structure with disable
 *
 * @param [in,out] flex_stats_pkt_attr_map_p - flex_stats_pkt_attr_map
 * @param [in]     disable                   - disable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_flex_stats_pkt_attr_map_t_disable_set(ifcs_flex_stats_pkt_attr_map_t *flex_stats_pkt_attr_map_p, ifcs_bool_t disable);

/**
 * @brief Get the flex_stats_pkt_attr_map structure with disable
 *
 * @param [in,out] flex_stats_pkt_attr_map_p - flex_stats_pkt_attr_map
 * @param [in]     disable_p                 - disable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_flex_stats_pkt_attr_map_t_disable_get(ifcs_flex_stats_pkt_attr_map_t *flex_stats_pkt_attr_map_p, ifcs_bool_t *disable_p);

/**
 * @brief Flex pool packet attribute map list
 */
typedef struct ifcs_flex_stats_pkt_attr_map_list_s {

    uint32_t                        count; ///< count
    ifcs_flex_stats_pkt_attr_map_t *arr;   ///< Flex pool packet attribute map list
} ifcs_flex_stats_pkt_attr_map_list_t;

/**
 * @brief VLAN tag operations when VLAN tag is not detected
 */
typedef struct ifcs_tag_action_if_tag_not_detected_s {

    ifcs_tag_action_if_tag_not_detected_cmd_t cmd;            ///< action command
    ifcs_uint8_t                              _dirty_cmd : 1; ///< indicates if user has set cmd
} ifcs_tag_action_if_tag_not_detected_t;

/**
 * @brief Initialize the tag_action_if_tag_not_detected structure
 *
 * @param [in,out] tag_action_if_tag_not_detected_p - tag_action_if_tag_not_detected
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_if_tag_not_detected_t_init(ifcs_tag_action_if_tag_not_detected_t *tag_action_if_tag_not_detected_p);
/**
 * @brief Set the tag_action_if_tag_not_detected structure with cmd
 *
 * @param [in,out] tag_action_if_tag_not_detected_p - tag_action_if_tag_not_detected
 * @param [in]     cmd                              - cmd
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_if_tag_not_detected_t_cmd_set(ifcs_tag_action_if_tag_not_detected_t *tag_action_if_tag_not_detected_p, ifcs_tag_action_if_tag_not_detected_cmd_t cmd);

/**
 * @brief Get the tag_action_if_tag_not_detected structure with cmd
 *
 * @param [in,out] tag_action_if_tag_not_detected_p - tag_action_if_tag_not_detected
 * @param [in]     cmd_p                            - cmd
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_if_tag_not_detected_t_cmd_get(ifcs_tag_action_if_tag_not_detected_t *tag_action_if_tag_not_detected_p, ifcs_tag_action_if_tag_not_detected_cmd_t *cmd_p);

/**
 * @brief VLAN tag operations when VLAN tag is detected
 */
typedef struct ifcs_tag_action_if_tag_detected_s {

    ifcs_tag_action_if_tag_detected_cmd_t   cmd;                              ///< action command
    ifcs_tag_action_replace_vid_cmd_t       replace_vid_cmd;                  ///< only valid if cmd is REPLACE
    ifcs_tag_action_replace_dot1p_cfi_cmd_t replace_dot1p_cfi_cmd;            ///< only valid if cmd is REPLACE
    ifcs_uint8_t                            _dirty_cmd : 1;                   ///< indicates if user has set cmd
    ifcs_uint8_t                            _dirty_replace_vid_cmd : 1;       ///< indicates if user has set replace_vid_cmd
    ifcs_uint8_t                            _dirty_replace_dot1p_cfi_cmd : 1; ///< indicates if user has set replace_dot1p_cfi_cmd
} ifcs_tag_action_if_tag_detected_t;

/**
 * @brief Initialize the tag_action_if_tag_detected structure
 *
 * @param [in,out] tag_action_if_tag_detected_p - tag_action_if_tag_detected
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_if_tag_detected_t_init(ifcs_tag_action_if_tag_detected_t *tag_action_if_tag_detected_p);
/**
 * @brief Set the tag_action_if_tag_detected structure with cmd
 *
 * @param [in,out] tag_action_if_tag_detected_p - tag_action_if_tag_detected
 * @param [in]     cmd                          - cmd
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_if_tag_detected_t_cmd_set(ifcs_tag_action_if_tag_detected_t *tag_action_if_tag_detected_p, ifcs_tag_action_if_tag_detected_cmd_t cmd);

/**
 * @brief Get the tag_action_if_tag_detected structure with cmd
 *
 * @param [in,out] tag_action_if_tag_detected_p - tag_action_if_tag_detected
 * @param [in]     cmd_p                        - cmd
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_if_tag_detected_t_cmd_get(ifcs_tag_action_if_tag_detected_t *tag_action_if_tag_detected_p, ifcs_tag_action_if_tag_detected_cmd_t *cmd_p);

/**
 * @brief Set the tag_action_if_tag_detected structure with replace_vid_cmd
 *
 * @param [in,out] tag_action_if_tag_detected_p - tag_action_if_tag_detected
 * @param [in]     replace_vid_cmd              - replace_vid_cmd
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_if_tag_detected_t_replace_vid_cmd_set(ifcs_tag_action_if_tag_detected_t *tag_action_if_tag_detected_p, ifcs_tag_action_replace_vid_cmd_t replace_vid_cmd);

/**
 * @brief Get the tag_action_if_tag_detected structure with replace_vid_cmd
 *
 * @param [in,out] tag_action_if_tag_detected_p - tag_action_if_tag_detected
 * @param [in]     replace_vid_cmd_p            - replace_vid_cmd
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_if_tag_detected_t_replace_vid_cmd_get(ifcs_tag_action_if_tag_detected_t *tag_action_if_tag_detected_p, ifcs_tag_action_replace_vid_cmd_t *replace_vid_cmd_p);

/**
 * @brief Set the tag_action_if_tag_detected structure with replace_dot1p_cfi_cmd
 *
 * @param [in,out] tag_action_if_tag_detected_p - tag_action_if_tag_detected
 * @param [in]     replace_dot1p_cfi_cmd        - replace_dot1p_cfi_cmd
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_if_tag_detected_t_replace_dot1p_cfi_cmd_set(ifcs_tag_action_if_tag_detected_t *tag_action_if_tag_detected_p, ifcs_tag_action_replace_dot1p_cfi_cmd_t replace_dot1p_cfi_cmd);

/**
 * @brief Get the tag_action_if_tag_detected structure with replace_dot1p_cfi_cmd
 *
 * @param [in,out] tag_action_if_tag_detected_p - tag_action_if_tag_detected
 * @param [in]     replace_dot1p_cfi_cmd_p      - replace_dot1p_cfi_cmd
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_if_tag_detected_t_replace_dot1p_cfi_cmd_get(ifcs_tag_action_if_tag_detected_t *tag_action_if_tag_detected_p, ifcs_tag_action_replace_dot1p_cfi_cmd_t *replace_dot1p_cfi_cmd_p);

/**
 * @brief VLAN tag dot1p and CFI controls for add or replace actions
 */
typedef struct ifcs_tag_action_dot1p_cfi_s {

    ifcs_dot1p_cfi_source_type_t dot1p_cfi_source;            ///< source for dot1p_cfi for the new or modified tag
    ifcs_handle_t                qosmap;                      ///< handle to qosmap of type TC_AND_COLOR_DOT1P; must specify when dot1p_cfi_source is use_map
    ifcs_uint8_t                 dot1p_value;                 ///< dot1p value when dot1p_cfi_source is use_value
    ifcs_uint8_t                 cfi_value;                   ///< cfi value when dot1p_cfi_source is use_value
    ifcs_uint8_t                 _dirty_dot1p_cfi_source : 1; ///< indicates if user has set dot1p_cfi_source
    ifcs_uint8_t                 _dirty_qosmap : 1;           ///< indicates if user has set qosmap
    ifcs_uint8_t                 _dirty_dot1p_value : 1;      ///< indicates if user has set dot1p_value
    ifcs_uint8_t                 _dirty_cfi_value : 1;        ///< indicates if user has set cfi_value
} ifcs_tag_action_dot1p_cfi_t;

/**
 * @brief Initialize the tag_action_dot1p_cfi structure
 *
 * @param [in,out] tag_action_dot1p_cfi_p - tag_action_dot1p_cfi
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_dot1p_cfi_t_init(ifcs_tag_action_dot1p_cfi_t *tag_action_dot1p_cfi_p);
/**
 * @brief Set the tag_action_dot1p_cfi structure with dot1p_cfi_source
 *
 * @param [in,out] tag_action_dot1p_cfi_p - tag_action_dot1p_cfi
 * @param [in]     dot1p_cfi_source       - dot1p_cfi_source
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_dot1p_cfi_t_dot1p_cfi_source_set(ifcs_tag_action_dot1p_cfi_t *tag_action_dot1p_cfi_p, ifcs_dot1p_cfi_source_type_t dot1p_cfi_source);

/**
 * @brief Get the tag_action_dot1p_cfi structure with dot1p_cfi_source
 *
 * @param [in,out] tag_action_dot1p_cfi_p - tag_action_dot1p_cfi
 * @param [in]     dot1p_cfi_source_p     - dot1p_cfi_source
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_dot1p_cfi_t_dot1p_cfi_source_get(ifcs_tag_action_dot1p_cfi_t *tag_action_dot1p_cfi_p, ifcs_dot1p_cfi_source_type_t *dot1p_cfi_source_p);

/**
 * @brief Set the tag_action_dot1p_cfi structure with qosmap
 *
 * @param [in,out] tag_action_dot1p_cfi_p - tag_action_dot1p_cfi
 * @param [in]     qosmap                 - qosmap
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_dot1p_cfi_t_qosmap_set(ifcs_tag_action_dot1p_cfi_t *tag_action_dot1p_cfi_p, ifcs_handle_t qosmap);

/**
 * @brief Get the tag_action_dot1p_cfi structure with qosmap
 *
 * @param [in,out] tag_action_dot1p_cfi_p - tag_action_dot1p_cfi
 * @param [in]     qosmap_p               - qosmap
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_dot1p_cfi_t_qosmap_get(ifcs_tag_action_dot1p_cfi_t *tag_action_dot1p_cfi_p, ifcs_handle_t *qosmap_p);

/**
 * @brief Set the tag_action_dot1p_cfi structure with dot1p_value
 *
 * @param [in,out] tag_action_dot1p_cfi_p - tag_action_dot1p_cfi
 * @param [in]     dot1p_value            - dot1p_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_dot1p_cfi_t_dot1p_value_set(ifcs_tag_action_dot1p_cfi_t *tag_action_dot1p_cfi_p, ifcs_uint8_t dot1p_value);

/**
 * @brief Get the tag_action_dot1p_cfi structure with dot1p_value
 *
 * @param [in,out] tag_action_dot1p_cfi_p - tag_action_dot1p_cfi
 * @param [in]     dot1p_value_p          - dot1p_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_dot1p_cfi_t_dot1p_value_get(ifcs_tag_action_dot1p_cfi_t *tag_action_dot1p_cfi_p, ifcs_uint8_t *dot1p_value_p);

/**
 * @brief Set the tag_action_dot1p_cfi structure with cfi_value
 *
 * @param [in,out] tag_action_dot1p_cfi_p - tag_action_dot1p_cfi
 * @param [in]     cfi_value              - cfi_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_dot1p_cfi_t_cfi_value_set(ifcs_tag_action_dot1p_cfi_t *tag_action_dot1p_cfi_p, ifcs_uint8_t cfi_value);

/**
 * @brief Get the tag_action_dot1p_cfi structure with cfi_value
 *
 * @param [in,out] tag_action_dot1p_cfi_p - tag_action_dot1p_cfi
 * @param [in]     cfi_value_p            - cfi_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_dot1p_cfi_t_cfi_value_get(ifcs_tag_action_dot1p_cfi_t *tag_action_dot1p_cfi_p, ifcs_uint8_t *cfi_value_p);

/**
 * @brief VLAN tag dot1p and CFI controls for add or replace actions
 */
typedef struct ifcs_tag_action_param_s {

    ifcs_uint16_t               vid_value;            ///< VLAN id when action is add or replace
    ifcs_tag_action_dot1p_cfi_t dot1p_cfi;            ///< dot1p and cfi when action is of type replace or add
    ifcs_uint8_t                _dirty_vid_value : 1; ///< indicates if user has set vid_value
    ifcs_uint8_t                _dirty_dot1p_cfi : 1; ///< indicates if user has set dot1p_cfi
} ifcs_tag_action_param_t;

/**
 * @brief Initialize the tag_action_param structure
 *
 * @param [in,out] tag_action_param_p - tag_action_param
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_param_t_init(ifcs_tag_action_param_t *tag_action_param_p);
/**
 * @brief Set the tag_action_param structure with vid_value
 *
 * @param [in,out] tag_action_param_p - tag_action_param
 * @param [in]     vid_value          - vid_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_param_t_vid_value_set(ifcs_tag_action_param_t *tag_action_param_p, ifcs_uint16_t vid_value);

/**
 * @brief Get the tag_action_param structure with vid_value
 *
 * @param [in,out] tag_action_param_p - tag_action_param
 * @param [in]     vid_value_p        - vid_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_param_t_vid_value_get(ifcs_tag_action_param_t *tag_action_param_p, ifcs_uint16_t *vid_value_p);

/**
 * @brief Set the tag_action_param structure with dot1p_cfi
 *
 * @param [in,out] tag_action_param_p - tag_action_param
 * @param [in]     dot1p_cfi_p        - dot1p_cfi
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_param_t_dot1p_cfi_set(ifcs_tag_action_param_t *tag_action_param_p, ifcs_tag_action_dot1p_cfi_t *dot1p_cfi_p);

/**
 * @brief Get the tag_action_param structure with dot1p_cfi
 *
 * @param [in,out] tag_action_param_p - tag_action_param
 * @param [in]     dot1p_cfi_p        - dot1p_cfi
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_tag_action_param_t_dot1p_cfi_get(ifcs_tag_action_param_t *tag_action_param_p, ifcs_tag_action_dot1p_cfi_t *dot1p_cfi_p);

/**
 * @brief data type to encode VLAN tag action
 */
typedef struct ifcs_vlan_tag_action_s {

    ifcs_tag_action_if_tag_not_detected_t action_if_tag_not_detected;            ///< action if tag is not detected
    ifcs_tag_action_if_tag_detected_t     action_if_tag_detected;                ///< action if tag is detected
    ifcs_tag_action_param_t               action_param;                          ///< common tag value parameters for add and replace actions
    ifcs_uint8_t                          _dirty_action_if_tag_not_detected : 1; ///< indicates if user has set action_if_tag_not_detected
    ifcs_uint8_t                          _dirty_action_if_tag_detected : 1;     ///< indicates if user has set action_if_tag_detected
    ifcs_uint8_t                          _dirty_action_param : 1;               ///< indicates if user has set action_param
} ifcs_vlan_tag_action_t;

/**
 * @brief Initialize the vlan_tag_action structure
 *
 * @param [in,out] vlan_tag_action_p            - vlan_tag_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_vlan_tag_action_t_init(ifcs_vlan_tag_action_t *vlan_tag_action_p);
/**
 * @brief Set the vlan_tag_action structure with action_if_tag_not_detected
 *
 * @param [in,out] vlan_tag_action_p            - vlan_tag_action
 * @param [in]     action_if_tag_not_detected_p - action_if_tag_not_detected
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_vlan_tag_action_t_action_if_tag_not_detected_set(ifcs_vlan_tag_action_t *vlan_tag_action_p, ifcs_tag_action_if_tag_not_detected_t *action_if_tag_not_detected_p);

/**
 * @brief Get the vlan_tag_action structure with action_if_tag_not_detected
 *
 * @param [in,out] vlan_tag_action_p            - vlan_tag_action
 * @param [in]     action_if_tag_not_detected_p - action_if_tag_not_detected
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_vlan_tag_action_t_action_if_tag_not_detected_get(ifcs_vlan_tag_action_t *vlan_tag_action_p, ifcs_tag_action_if_tag_not_detected_t *action_if_tag_not_detected_p);

/**
 * @brief Set the vlan_tag_action structure with action_if_tag_detected
 *
 * @param [in,out] vlan_tag_action_p            - vlan_tag_action
 * @param [in]     action_if_tag_detected_p     - action_if_tag_detected
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_vlan_tag_action_t_action_if_tag_detected_set(ifcs_vlan_tag_action_t *vlan_tag_action_p, ifcs_tag_action_if_tag_detected_t *action_if_tag_detected_p);

/**
 * @brief Get the vlan_tag_action structure with action_if_tag_detected
 *
 * @param [in,out] vlan_tag_action_p            - vlan_tag_action
 * @param [in]     action_if_tag_detected_p     - action_if_tag_detected
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_vlan_tag_action_t_action_if_tag_detected_get(ifcs_vlan_tag_action_t *vlan_tag_action_p, ifcs_tag_action_if_tag_detected_t *action_if_tag_detected_p);

/**
 * @brief Set the vlan_tag_action structure with action_param
 *
 * @param [in,out] vlan_tag_action_p            - vlan_tag_action
 * @param [in]     action_param_p               - action_param
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_vlan_tag_action_t_action_param_set(ifcs_vlan_tag_action_t *vlan_tag_action_p, ifcs_tag_action_param_t *action_param_p);

/**
 * @brief Get the vlan_tag_action structure with action_param
 *
 * @param [in,out] vlan_tag_action_p            - vlan_tag_action
 * @param [in]     action_param_p               - action_param
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_vlan_tag_action_t_action_param_get(ifcs_vlan_tag_action_t *vlan_tag_action_p, ifcs_tag_action_param_t *action_param_p);

/**
 * @brief sysport values to match
 */
typedef struct ifcs_ingress_vni_tag_map_key_sysport_s {

    ifcs_handle_t sysport;            ///< sysport handle
    ifcs_uint8_t  _dirty_sysport : 1; ///< indicates if user has set sysport
} ifcs_ingress_vni_tag_map_key_sysport_t;

/**
 * @brief Initialize the ingress_vni_tag_map_key_sysport structure
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_p - ingress_vni_tag_map_key_sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_t_init(ifcs_ingress_vni_tag_map_key_sysport_t *ingress_vni_tag_map_key_sysport_p);
/**
 * @brief Set the ingress_vni_tag_map_key_sysport structure with sysport
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_p - ingress_vni_tag_map_key_sysport
 * @param [in]     sysport                           - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_t_sysport_set(ifcs_ingress_vni_tag_map_key_sysport_t *ingress_vni_tag_map_key_sysport_p, ifcs_handle_t sysport);

/**
 * @brief Get the ingress_vni_tag_map_key_sysport structure with sysport
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_p - ingress_vni_tag_map_key_sysport
 * @param [in]     sysport_p                         - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_t_sysport_get(ifcs_ingress_vni_tag_map_key_sysport_t *ingress_vni_tag_map_key_sysport_p, ifcs_handle_t *sysport_p);

/**
 * @brief sysport and svid values to match
 */
typedef struct ifcs_ingress_vni_tag_map_key_sysport_svid_s {

    ifcs_handle_t sysport;            ///< sysport handle
    ifcs_uint16_t svid;               ///< SVLAN id
    ifcs_uint8_t  _dirty_sysport : 1; ///< indicates if user has set sysport
    ifcs_uint8_t  _dirty_svid : 1;    ///< indicates if user has set svid
} ifcs_ingress_vni_tag_map_key_sysport_svid_t;

/**
 * @brief Initialize the ingress_vni_tag_map_key_sysport_svid structure
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_svid_p - ingress_vni_tag_map_key_sysport_svid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_svid_t_init(ifcs_ingress_vni_tag_map_key_sysport_svid_t *ingress_vni_tag_map_key_sysport_svid_p);
/**
 * @brief Set the ingress_vni_tag_map_key_sysport_svid structure with sysport
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_svid_p - ingress_vni_tag_map_key_sysport_svid
 * @param [in]     sysport                                - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_svid_t_sysport_set(ifcs_ingress_vni_tag_map_key_sysport_svid_t *ingress_vni_tag_map_key_sysport_svid_p, ifcs_handle_t sysport);

/**
 * @brief Get the ingress_vni_tag_map_key_sysport_svid structure with sysport
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_svid_p - ingress_vni_tag_map_key_sysport_svid
 * @param [in]     sysport_p                              - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_svid_t_sysport_get(ifcs_ingress_vni_tag_map_key_sysport_svid_t *ingress_vni_tag_map_key_sysport_svid_p, ifcs_handle_t *sysport_p);

/**
 * @brief Set the ingress_vni_tag_map_key_sysport_svid structure with svid
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_svid_p - ingress_vni_tag_map_key_sysport_svid
 * @param [in]     svid                                   - svid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_svid_t_svid_set(ifcs_ingress_vni_tag_map_key_sysport_svid_t *ingress_vni_tag_map_key_sysport_svid_p, ifcs_uint16_t svid);

/**
 * @brief Get the ingress_vni_tag_map_key_sysport_svid structure with svid
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_svid_p - ingress_vni_tag_map_key_sysport_svid
 * @param [in]     svid_p                                 - svid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_svid_t_svid_get(ifcs_ingress_vni_tag_map_key_sysport_svid_t *ingress_vni_tag_map_key_sysport_svid_p, ifcs_uint16_t *svid_p);

/**
 * @brief sysport and cvid values to match
 */
typedef struct ifcs_ingress_vni_tag_map_key_sysport_cvid_s {

    ifcs_handle_t sysport;            ///< sysport handle
    ifcs_uint16_t cvid;               ///< CVLAN id
    ifcs_uint8_t  _dirty_sysport : 1; ///< indicates if user has set sysport
    ifcs_uint8_t  _dirty_cvid : 1;    ///< indicates if user has set cvid
} ifcs_ingress_vni_tag_map_key_sysport_cvid_t;

/**
 * @brief Initialize the ingress_vni_tag_map_key_sysport_cvid structure
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_cvid_p - ingress_vni_tag_map_key_sysport_cvid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_cvid_t_init(ifcs_ingress_vni_tag_map_key_sysport_cvid_t *ingress_vni_tag_map_key_sysport_cvid_p);
/**
 * @brief Set the ingress_vni_tag_map_key_sysport_cvid structure with sysport
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_cvid_p - ingress_vni_tag_map_key_sysport_cvid
 * @param [in]     sysport                                - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_cvid_t_sysport_set(ifcs_ingress_vni_tag_map_key_sysport_cvid_t *ingress_vni_tag_map_key_sysport_cvid_p, ifcs_handle_t sysport);

/**
 * @brief Get the ingress_vni_tag_map_key_sysport_cvid structure with sysport
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_cvid_p - ingress_vni_tag_map_key_sysport_cvid
 * @param [in]     sysport_p                              - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_cvid_t_sysport_get(ifcs_ingress_vni_tag_map_key_sysport_cvid_t *ingress_vni_tag_map_key_sysport_cvid_p, ifcs_handle_t *sysport_p);

/**
 * @brief Set the ingress_vni_tag_map_key_sysport_cvid structure with cvid
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_cvid_p - ingress_vni_tag_map_key_sysport_cvid
 * @param [in]     cvid                                   - cvid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_cvid_t_cvid_set(ifcs_ingress_vni_tag_map_key_sysport_cvid_t *ingress_vni_tag_map_key_sysport_cvid_p, ifcs_uint16_t cvid);

/**
 * @brief Get the ingress_vni_tag_map_key_sysport_cvid structure with cvid
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_cvid_p - ingress_vni_tag_map_key_sysport_cvid
 * @param [in]     cvid_p                                 - cvid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_cvid_t_cvid_get(ifcs_ingress_vni_tag_map_key_sysport_cvid_t *ingress_vni_tag_map_key_sysport_cvid_p, ifcs_uint16_t *cvid_p);

/**
 * @brief sysport, cvid and svid values to match
 */
typedef struct ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_s {

    ifcs_handle_t sysport;            ///< sysport handle
    ifcs_uint16_t svid;               ///< SVLAN id
    ifcs_uint16_t cvid;               ///< CVLAN id
    ifcs_uint8_t  _dirty_sysport : 1; ///< indicates if user has set sysport
    ifcs_uint8_t  _dirty_svid : 1;    ///< indicates if user has set svid
    ifcs_uint8_t  _dirty_cvid : 1;    ///< indicates if user has set cvid
} ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t;

/**
 * @brief Initialize the ingress_vni_tag_map_key_sysport_svid_cvid structure
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_svid_cvid_p - ingress_vni_tag_map_key_sysport_svid_cvid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t_init(ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t *ingress_vni_tag_map_key_sysport_svid_cvid_p);
/**
 * @brief Set the ingress_vni_tag_map_key_sysport_svid_cvid structure with sysport
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_svid_cvid_p - ingress_vni_tag_map_key_sysport_svid_cvid
 * @param [in]     sysport                                     - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t_sysport_set(ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t *ingress_vni_tag_map_key_sysport_svid_cvid_p, ifcs_handle_t sysport);

/**
 * @brief Get the ingress_vni_tag_map_key_sysport_svid_cvid structure with sysport
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_svid_cvid_p - ingress_vni_tag_map_key_sysport_svid_cvid
 * @param [in]     sysport_p                                   - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t_sysport_get(ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t *ingress_vni_tag_map_key_sysport_svid_cvid_p, ifcs_handle_t *sysport_p);

/**
 * @brief Set the ingress_vni_tag_map_key_sysport_svid_cvid structure with svid
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_svid_cvid_p - ingress_vni_tag_map_key_sysport_svid_cvid
 * @param [in]     svid                                        - svid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t_svid_set(ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t *ingress_vni_tag_map_key_sysport_svid_cvid_p, ifcs_uint16_t svid);

/**
 * @brief Get the ingress_vni_tag_map_key_sysport_svid_cvid structure with svid
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_svid_cvid_p - ingress_vni_tag_map_key_sysport_svid_cvid
 * @param [in]     svid_p                                      - svid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t_svid_get(ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t *ingress_vni_tag_map_key_sysport_svid_cvid_p, ifcs_uint16_t *svid_p);

/**
 * @brief Set the ingress_vni_tag_map_key_sysport_svid_cvid structure with cvid
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_svid_cvid_p - ingress_vni_tag_map_key_sysport_svid_cvid
 * @param [in]     cvid                                        - cvid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t_cvid_set(ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t *ingress_vni_tag_map_key_sysport_svid_cvid_p, ifcs_uint16_t cvid);

/**
 * @brief Get the ingress_vni_tag_map_key_sysport_svid_cvid structure with cvid
 *
 * @param [in,out] ingress_vni_tag_map_key_sysport_svid_cvid_p - ingress_vni_tag_map_key_sysport_svid_cvid
 * @param [in]     cvid_p                                      - cvid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t_cvid_get(ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t *ingress_vni_tag_map_key_sysport_svid_cvid_p, ifcs_uint16_t *cvid_p);

/**
 * @brief ingress vni tag mapper key
 */
typedef union ifcs_ingress_vni_tag_map_key_u {

    ifcs_ingress_vni_tag_map_key_sysport_t           sysport;           ///< key with sysport
    ifcs_ingress_vni_tag_map_key_sysport_cvid_t      sysport_cvid;      ///< key with sysport and cvid
    ifcs_ingress_vni_tag_map_key_sysport_svid_t      sysport_svid;      ///< key with sysport and svid
    ifcs_ingress_vni_tag_map_key_sysport_svid_cvid_t sysport_svid_cvid; ///< key with sysport, svid, cvid
} ifcs_ingress_vni_tag_map_key_t;

/**
 * @brief L2VNI values to match
 */
typedef struct ifcs_egress_vlan_tag_map_key_l2vni_s {

    ifcs_handle_t l2vni;            ///< L2VNI handle
    ifcs_uint8_t  _dirty_l2vni : 1; ///< indicates if user has set l2vni
} ifcs_egress_vlan_tag_map_key_l2vni_t;

/**
 * @brief Initialize the egress_vlan_tag_map_key_l2vni structure
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_p - egress_vlan_tag_map_key_l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_t_init(ifcs_egress_vlan_tag_map_key_l2vni_t *egress_vlan_tag_map_key_l2vni_p);
/**
 * @brief Set the egress_vlan_tag_map_key_l2vni structure with l2vni
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_p - egress_vlan_tag_map_key_l2vni
 * @param [in]     l2vni                           - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_t_l2vni_set(ifcs_egress_vlan_tag_map_key_l2vni_t *egress_vlan_tag_map_key_l2vni_p, ifcs_handle_t l2vni);

/**
 * @brief Get the egress_vlan_tag_map_key_l2vni structure with l2vni
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_p - egress_vlan_tag_map_key_l2vni
 * @param [in]     l2vni_p                         - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_t_l2vni_get(ifcs_egress_vlan_tag_map_key_l2vni_t *egress_vlan_tag_map_key_l2vni_p, ifcs_handle_t *l2vni_p);

/**
 * @brief Sysport, L2VNI values to match
 */
typedef struct ifcs_egress_vlan_tag_map_key_l2vni_sysport_s {

    ifcs_handle_t l2vni;              ///< L2VNI handle
    ifcs_handle_t sysport;            ///< sysport handle
    ifcs_uint8_t  _dirty_l2vni : 1;   ///< indicates if user has set l2vni
    ifcs_uint8_t  _dirty_sysport : 1; ///< indicates if user has set sysport
} ifcs_egress_vlan_tag_map_key_l2vni_sysport_t;

/**
 * @brief Initialize the egress_vlan_tag_map_key_l2vni_sysport structure
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_p - egress_vlan_tag_map_key_l2vni_sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_t_init(ifcs_egress_vlan_tag_map_key_l2vni_sysport_t *egress_vlan_tag_map_key_l2vni_sysport_p);
/**
 * @brief Set the egress_vlan_tag_map_key_l2vni_sysport structure with l2vni
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_p - egress_vlan_tag_map_key_l2vni_sysport
 * @param [in]     l2vni                                   - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_t_l2vni_set(ifcs_egress_vlan_tag_map_key_l2vni_sysport_t *egress_vlan_tag_map_key_l2vni_sysport_p, ifcs_handle_t l2vni);

/**
 * @brief Get the egress_vlan_tag_map_key_l2vni_sysport structure with l2vni
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_p - egress_vlan_tag_map_key_l2vni_sysport
 * @param [in]     l2vni_p                                 - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_t_l2vni_get(ifcs_egress_vlan_tag_map_key_l2vni_sysport_t *egress_vlan_tag_map_key_l2vni_sysport_p, ifcs_handle_t *l2vni_p);

/**
 * @brief Set the egress_vlan_tag_map_key_l2vni_sysport structure with sysport
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_p - egress_vlan_tag_map_key_l2vni_sysport
 * @param [in]     sysport                                 - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_t_sysport_set(ifcs_egress_vlan_tag_map_key_l2vni_sysport_t *egress_vlan_tag_map_key_l2vni_sysport_p, ifcs_handle_t sysport);

/**
 * @brief Get the egress_vlan_tag_map_key_l2vni_sysport structure with sysport
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_p - egress_vlan_tag_map_key_l2vni_sysport
 * @param [in]     sysport_p                               - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_t_sysport_get(ifcs_egress_vlan_tag_map_key_l2vni_sysport_t *egress_vlan_tag_map_key_l2vni_sysport_p, ifcs_handle_t *sysport_p);

/**
 * @brief Sysport, L2VNI, SVID values to match
 */
typedef struct ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_s {

    ifcs_handle_t l2vni;              ///< L2VNI handle
    ifcs_handle_t sysport;            ///< sysport handle
    ifcs_uint16_t svid;               ///< SVLAN id
    ifcs_uint8_t  _dirty_l2vni : 1;   ///< indicates if user has set l2vni
    ifcs_uint8_t  _dirty_sysport : 1; ///< indicates if user has set sysport
    ifcs_uint8_t  _dirty_svid : 1;    ///< indicates if user has set svid
} ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t;

/**
 * @brief Initialize the egress_vlan_tag_map_key_l2vni_sysport_svid structure
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_p - egress_vlan_tag_map_key_l2vni_sysport_svid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t_init(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_p);
/**
 * @brief Set the egress_vlan_tag_map_key_l2vni_sysport_svid structure with l2vni
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_p - egress_vlan_tag_map_key_l2vni_sysport_svid
 * @param [in]     l2vni                                        - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t_l2vni_set(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_p, ifcs_handle_t l2vni);

/**
 * @brief Get the egress_vlan_tag_map_key_l2vni_sysport_svid structure with l2vni
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_p - egress_vlan_tag_map_key_l2vni_sysport_svid
 * @param [in]     l2vni_p                                      - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t_l2vni_get(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_p, ifcs_handle_t *l2vni_p);

/**
 * @brief Set the egress_vlan_tag_map_key_l2vni_sysport_svid structure with sysport
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_p - egress_vlan_tag_map_key_l2vni_sysport_svid
 * @param [in]     sysport                                      - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t_sysport_set(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_p, ifcs_handle_t sysport);

/**
 * @brief Get the egress_vlan_tag_map_key_l2vni_sysport_svid structure with sysport
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_p - egress_vlan_tag_map_key_l2vni_sysport_svid
 * @param [in]     sysport_p                                    - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t_sysport_get(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_p, ifcs_handle_t *sysport_p);

/**
 * @brief Set the egress_vlan_tag_map_key_l2vni_sysport_svid structure with svid
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_p - egress_vlan_tag_map_key_l2vni_sysport_svid
 * @param [in]     svid                                         - svid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t_svid_set(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_p, ifcs_uint16_t svid);

/**
 * @brief Get the egress_vlan_tag_map_key_l2vni_sysport_svid structure with svid
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_p - egress_vlan_tag_map_key_l2vni_sysport_svid
 * @param [in]     svid_p                                       - svid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t_svid_get(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_p, ifcs_uint16_t *svid_p);

/**
 * @brief Sysport, L2VNI, CVID values to match
 */
typedef struct ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_s {

    ifcs_handle_t l2vni;              ///< L2VNI handle
    ifcs_handle_t sysport;            ///< sysport handle
    ifcs_uint16_t cvid;               ///< CVLAN id
    ifcs_uint8_t  _dirty_l2vni : 1;   ///< indicates if user has set l2vni
    ifcs_uint8_t  _dirty_sysport : 1; ///< indicates if user has set sysport
    ifcs_uint8_t  _dirty_cvid : 1;    ///< indicates if user has set cvid
} ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t;

/**
 * @brief Initialize the egress_vlan_tag_map_key_l2vni_sysport_cvid structure
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_cvid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t_init(ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_cvid_p);
/**
 * @brief Set the egress_vlan_tag_map_key_l2vni_sysport_cvid structure with l2vni
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_cvid
 * @param [in]     l2vni                                        - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t_l2vni_set(ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_cvid_p, ifcs_handle_t l2vni);

/**
 * @brief Get the egress_vlan_tag_map_key_l2vni_sysport_cvid structure with l2vni
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_cvid
 * @param [in]     l2vni_p                                      - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t_l2vni_get(ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_cvid_p, ifcs_handle_t *l2vni_p);

/**
 * @brief Set the egress_vlan_tag_map_key_l2vni_sysport_cvid structure with sysport
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_cvid
 * @param [in]     sysport                                      - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t_sysport_set(ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_cvid_p, ifcs_handle_t sysport);

/**
 * @brief Get the egress_vlan_tag_map_key_l2vni_sysport_cvid structure with sysport
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_cvid
 * @param [in]     sysport_p                                    - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t_sysport_get(ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_cvid_p, ifcs_handle_t *sysport_p);

/**
 * @brief Set the egress_vlan_tag_map_key_l2vni_sysport_cvid structure with cvid
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_cvid
 * @param [in]     cvid                                         - cvid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t_cvid_set(ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_cvid_p, ifcs_uint16_t cvid);

/**
 * @brief Get the egress_vlan_tag_map_key_l2vni_sysport_cvid structure with cvid
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_cvid
 * @param [in]     cvid_p                                       - cvid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t_cvid_get(ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_cvid_p, ifcs_uint16_t *cvid_p);

/**
 * @brief Sysport, L2VNI, SVID and CVID values to match
 */
typedef struct ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_s {

    ifcs_handle_t l2vni;              ///< L2VNI handle
    ifcs_handle_t sysport;            ///< sysport handle
    ifcs_uint16_t svid;               ///< SVLAN id
    ifcs_uint16_t cvid;               ///< CVLAN id
    ifcs_uint8_t  _dirty_l2vni : 1;   ///< indicates if user has set l2vni
    ifcs_uint8_t  _dirty_sysport : 1; ///< indicates if user has set sysport
    ifcs_uint8_t  _dirty_svid : 1;    ///< indicates if user has set svid
    ifcs_uint8_t  _dirty_cvid : 1;    ///< indicates if user has set cvid
} ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t;

/**
 * @brief Initialize the egress_vlan_tag_map_key_l2vni_sysport_svid_cvid structure
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_svid_cvid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t_init(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p);
/**
 * @brief Set the egress_vlan_tag_map_key_l2vni_sysport_svid_cvid structure with l2vni
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_svid_cvid
 * @param [in]     l2vni                                             - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t_l2vni_set(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p, ifcs_handle_t l2vni);

/**
 * @brief Get the egress_vlan_tag_map_key_l2vni_sysport_svid_cvid structure with l2vni
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_svid_cvid
 * @param [in]     l2vni_p                                           - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t_l2vni_get(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p, ifcs_handle_t *l2vni_p);

/**
 * @brief Set the egress_vlan_tag_map_key_l2vni_sysport_svid_cvid structure with sysport
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_svid_cvid
 * @param [in]     sysport                                           - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t_sysport_set(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p, ifcs_handle_t sysport);

/**
 * @brief Get the egress_vlan_tag_map_key_l2vni_sysport_svid_cvid structure with sysport
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_svid_cvid
 * @param [in]     sysport_p                                         - sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t_sysport_get(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p, ifcs_handle_t *sysport_p);

/**
 * @brief Set the egress_vlan_tag_map_key_l2vni_sysport_svid_cvid structure with svid
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_svid_cvid
 * @param [in]     svid                                              - svid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t_svid_set(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p, ifcs_uint16_t svid);

/**
 * @brief Get the egress_vlan_tag_map_key_l2vni_sysport_svid_cvid structure with svid
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_svid_cvid
 * @param [in]     svid_p                                            - svid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t_svid_get(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p, ifcs_uint16_t *svid_p);

/**
 * @brief Set the egress_vlan_tag_map_key_l2vni_sysport_svid_cvid structure with cvid
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_svid_cvid
 * @param [in]     cvid                                              - cvid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t_cvid_set(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p, ifcs_uint16_t cvid);

/**
 * @brief Get the egress_vlan_tag_map_key_l2vni_sysport_svid_cvid structure with cvid
 *
 * @param [in,out] egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p - egress_vlan_tag_map_key_l2vni_sysport_svid_cvid
 * @param [in]     cvid_p                                            - cvid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t_cvid_get(ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t *egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_p, ifcs_uint16_t *cvid_p);

/**
 * @brief egress vni tag mapper key
 */
typedef union ifcs_egress_vlan_tag_map_key_u {

    ifcs_egress_vlan_tag_map_key_l2vni_t                   l2vni;                   ///< l2vni in key
    ifcs_egress_vlan_tag_map_key_l2vni_sysport_t           l2vni_sysport;           ///< sysport and l2vni in  key
    ifcs_egress_vlan_tag_map_key_l2vni_sysport_cvid_t      l2vni_sysport_cvid;      ///< l2vni_sysport_cvid in key
    ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_t      l2vni_sysport_svid;      ///< l2vni_sysport_svid in key
    ifcs_egress_vlan_tag_map_key_l2vni_sysport_svid_cvid_t l2vni_sysport_svid_cvid; ///< l2vni_sysport_svid_cvid in key
} ifcs_egress_vlan_tag_map_key_t;

/**
 * @brief route with keys as S,G and L3VNI
 */
typedef struct ifcs_mcast_route_key_ip_sg_l3vni_s {

    ifcs_handle_t    l3vni;             ///< L3VNI handle
    ifcs_ip_prefix_t source;            ///< Multicast sender IP
    ifcs_ip_prefix_t group;             ///< Multicast group IP
    ifcs_uint8_t     _dirty_l3vni : 1;  ///< indicates if user has set l3vni
    ifcs_uint8_t     _dirty_source : 1; ///< indicates if user has set source
    ifcs_uint8_t     _dirty_group : 1;  ///< indicates if user has set group
} ifcs_mcast_route_key_ip_sg_l3vni_t;

/**
 * @brief Initialize the mcast_route_key_ip_sg_l3vni structure
 *
 * @param [in,out] mcast_route_key_ip_sg_l3vni_p - mcast_route_key_ip_sg_l3vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_mcast_route_key_ip_sg_l3vni_t_init(ifcs_mcast_route_key_ip_sg_l3vni_t *mcast_route_key_ip_sg_l3vni_p);
/**
 * @brief Set the mcast_route_key_ip_sg_l3vni structure with l3vni
 *
 * @param [in,out] mcast_route_key_ip_sg_l3vni_p - mcast_route_key_ip_sg_l3vni
 * @param [in]     l3vni                         - l3vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_mcast_route_key_ip_sg_l3vni_t_l3vni_set(ifcs_mcast_route_key_ip_sg_l3vni_t *mcast_route_key_ip_sg_l3vni_p, ifcs_handle_t l3vni);

/**
 * @brief Get the mcast_route_key_ip_sg_l3vni structure with l3vni
 *
 * @param [in,out] mcast_route_key_ip_sg_l3vni_p - mcast_route_key_ip_sg_l3vni
 * @param [in]     l3vni_p                       - l3vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_mcast_route_key_ip_sg_l3vni_t_l3vni_get(ifcs_mcast_route_key_ip_sg_l3vni_t *mcast_route_key_ip_sg_l3vni_p, ifcs_handle_t *l3vni_p);

/**
 * @brief Set the mcast_route_key_ip_sg_l3vni structure with source
 *
 * @param [in,out] mcast_route_key_ip_sg_l3vni_p - mcast_route_key_ip_sg_l3vni
 * @param [in]     source_p                      - source
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_mcast_route_key_ip_sg_l3vni_t_source_set(ifcs_mcast_route_key_ip_sg_l3vni_t *mcast_route_key_ip_sg_l3vni_p, ifcs_ip_prefix_t *source_p);

/**
 * @brief Get the mcast_route_key_ip_sg_l3vni structure with source
 *
 * @param [in,out] mcast_route_key_ip_sg_l3vni_p - mcast_route_key_ip_sg_l3vni
 * @param [in]     source_p                      - source
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_mcast_route_key_ip_sg_l3vni_t_source_get(ifcs_mcast_route_key_ip_sg_l3vni_t *mcast_route_key_ip_sg_l3vni_p, ifcs_ip_prefix_t *source_p);

/**
 * @brief Set the mcast_route_key_ip_sg_l3vni structure with group
 *
 * @param [in,out] mcast_route_key_ip_sg_l3vni_p - mcast_route_key_ip_sg_l3vni
 * @param [in]     group_p                       - group
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_mcast_route_key_ip_sg_l3vni_t_group_set(ifcs_mcast_route_key_ip_sg_l3vni_t *mcast_route_key_ip_sg_l3vni_p, ifcs_ip_prefix_t *group_p);

/**
 * @brief Get the mcast_route_key_ip_sg_l3vni structure with group
 *
 * @param [in,out] mcast_route_key_ip_sg_l3vni_p - mcast_route_key_ip_sg_l3vni
 * @param [in]     group_p                       - group
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_mcast_route_key_ip_sg_l3vni_t_group_get(ifcs_mcast_route_key_ip_sg_l3vni_t *mcast_route_key_ip_sg_l3vni_p, ifcs_ip_prefix_t *group_p);

/**
 * @brief route with keys as *,G and L3VNI
 */
typedef struct ifcs_mcast_route_key_ip_starg_l3vni_s {

    ifcs_handle_t    l3vni;            ///< L3VNI handle
    ifcs_ip_prefix_t group;            ///< Multicast group IP
    ifcs_uint8_t     _dirty_l3vni : 1; ///< indicates if user has set l3vni
    ifcs_uint8_t     _dirty_group : 1; ///< indicates if user has set group
} ifcs_mcast_route_key_ip_starg_l3vni_t;

/**
 * @brief Initialize the mcast_route_key_ip_starg_l3vni structure
 *
 * @param [in,out] mcast_route_key_ip_starg_l3vni_p - mcast_route_key_ip_starg_l3vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_mcast_route_key_ip_starg_l3vni_t_init(ifcs_mcast_route_key_ip_starg_l3vni_t *mcast_route_key_ip_starg_l3vni_p);
/**
 * @brief Set the mcast_route_key_ip_starg_l3vni structure with l3vni
 *
 * @param [in,out] mcast_route_key_ip_starg_l3vni_p - mcast_route_key_ip_starg_l3vni
 * @param [in]     l3vni                            - l3vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_mcast_route_key_ip_starg_l3vni_t_l3vni_set(ifcs_mcast_route_key_ip_starg_l3vni_t *mcast_route_key_ip_starg_l3vni_p, ifcs_handle_t l3vni);

/**
 * @brief Get the mcast_route_key_ip_starg_l3vni structure with l3vni
 *
 * @param [in,out] mcast_route_key_ip_starg_l3vni_p - mcast_route_key_ip_starg_l3vni
 * @param [in]     l3vni_p                          - l3vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_mcast_route_key_ip_starg_l3vni_t_l3vni_get(ifcs_mcast_route_key_ip_starg_l3vni_t *mcast_route_key_ip_starg_l3vni_p, ifcs_handle_t *l3vni_p);

/**
 * @brief Set the mcast_route_key_ip_starg_l3vni structure with group
 *
 * @param [in,out] mcast_route_key_ip_starg_l3vni_p - mcast_route_key_ip_starg_l3vni
 * @param [in]     group_p                          - group
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_mcast_route_key_ip_starg_l3vni_t_group_set(ifcs_mcast_route_key_ip_starg_l3vni_t *mcast_route_key_ip_starg_l3vni_p, ifcs_ip_prefix_t *group_p);

/**
 * @brief Get the mcast_route_key_ip_starg_l3vni structure with group
 *
 * @param [in,out] mcast_route_key_ip_starg_l3vni_p - mcast_route_key_ip_starg_l3vni
 * @param [in]     group_p                          - group
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_mcast_route_key_ip_starg_l3vni_t_group_get(ifcs_mcast_route_key_ip_starg_l3vni_t *mcast_route_key_ip_starg_l3vni_p, ifcs_ip_prefix_t *group_p);

/**
 * @brief Multicast route key mapper
 */
typedef union ifcs_mcast_route_key_map_u {

    ifcs_mcast_route_key_ip_sg_l3vni_t    ip_sg_l3vni;    ///< Type SG,L3VNI key
    ifcs_mcast_route_key_ip_starg_l3vni_t ip_starg_l3vni; ///< Type *G,L3VNI key
} ifcs_mcast_route_key_map_t;

/**
 * @brief Ingress tunnel vni map entry key match fields for IPv4 GRE tunnels
 */
typedef struct ifcs_ingress_tunnel_vni_ipv4_gre_key_s {

    ifcs_uint32_t packet_value;            ///< GRE key for IPv4 GRE tunnels
    ifcs_uint8_t  _dirty_packet_value : 1; ///< indicates if user has set packet_value
} ifcs_ingress_tunnel_vni_ipv4_gre_key_t;

/**
 * @brief Initialize the ingress_tunnel_vni_ipv4_gre_key structure
 *
 * @param [in,out] ingress_tunnel_vni_ipv4_gre_key_p - ingress_tunnel_vni_ipv4_gre_key
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_tunnel_vni_ipv4_gre_key_t_init(ifcs_ingress_tunnel_vni_ipv4_gre_key_t *ingress_tunnel_vni_ipv4_gre_key_p);
/**
 * @brief Set the ingress_tunnel_vni_ipv4_gre_key structure with packet_value
 *
 * @param [in,out] ingress_tunnel_vni_ipv4_gre_key_p - ingress_tunnel_vni_ipv4_gre_key
 * @param [in]     packet_value                      - packet_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_tunnel_vni_ipv4_gre_key_t_packet_value_set(ifcs_ingress_tunnel_vni_ipv4_gre_key_t *ingress_tunnel_vni_ipv4_gre_key_p, ifcs_uint32_t packet_value);

/**
 * @brief Get the ingress_tunnel_vni_ipv4_gre_key structure with packet_value
 *
 * @param [in,out] ingress_tunnel_vni_ipv4_gre_key_p - ingress_tunnel_vni_ipv4_gre_key
 * @param [in]     packet_value_p                    - packet_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_tunnel_vni_ipv4_gre_key_t_packet_value_get(ifcs_ingress_tunnel_vni_ipv4_gre_key_t *ingress_tunnel_vni_ipv4_gre_key_p, ifcs_uint32_t *packet_value_p);

/**
 * @brief Ingress tunnel vni map entry key match fields for IPv6 GRE tunnels
 */
typedef struct ifcs_ingress_tunnel_vni_ipv6_gre_key_s {

    ifcs_uint32_t packet_value;            ///< GRE key for IPv6 GRE tunnels
    ifcs_uint8_t  _dirty_packet_value : 1; ///< indicates if user has set packet_value
} ifcs_ingress_tunnel_vni_ipv6_gre_key_t;

/**
 * @brief Initialize the ingress_tunnel_vni_ipv6_gre_key structure
 *
 * @param [in,out] ingress_tunnel_vni_ipv6_gre_key_p - ingress_tunnel_vni_ipv6_gre_key
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_tunnel_vni_ipv6_gre_key_t_init(ifcs_ingress_tunnel_vni_ipv6_gre_key_t *ingress_tunnel_vni_ipv6_gre_key_p);
/**
 * @brief Set the ingress_tunnel_vni_ipv6_gre_key structure with packet_value
 *
 * @param [in,out] ingress_tunnel_vni_ipv6_gre_key_p - ingress_tunnel_vni_ipv6_gre_key
 * @param [in]     packet_value                      - packet_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_tunnel_vni_ipv6_gre_key_t_packet_value_set(ifcs_ingress_tunnel_vni_ipv6_gre_key_t *ingress_tunnel_vni_ipv6_gre_key_p, ifcs_uint32_t packet_value);

/**
 * @brief Get the ingress_tunnel_vni_ipv6_gre_key structure with packet_value
 *
 * @param [in,out] ingress_tunnel_vni_ipv6_gre_key_p - ingress_tunnel_vni_ipv6_gre_key
 * @param [in]     packet_value_p                    - packet_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_tunnel_vni_ipv6_gre_key_t_packet_value_get(ifcs_ingress_tunnel_vni_ipv6_gre_key_t *ingress_tunnel_vni_ipv6_gre_key_p, ifcs_uint32_t *packet_value_p);

/**
 * @brief Ingress tunnel vni map entry key match fields for IPv4 Vxlan tunnels
 */
typedef struct ifcs_ingress_tunnel_vni_ipv4_vxlan_key_s {

    ifcs_uint32_t packet_value;            ///< VxLAN VNID for IPv4 Vxlan tunnels
    ifcs_uint8_t  _dirty_packet_value : 1; ///< indicates if user has set packet_value
} ifcs_ingress_tunnel_vni_ipv4_vxlan_key_t;

/**
 * @brief Initialize the ingress_tunnel_vni_ipv4_vxlan_key structure
 *
 * @param [in,out] ingress_tunnel_vni_ipv4_vxlan_key_p - ingress_tunnel_vni_ipv4_vxlan_key
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_tunnel_vni_ipv4_vxlan_key_t_init(ifcs_ingress_tunnel_vni_ipv4_vxlan_key_t *ingress_tunnel_vni_ipv4_vxlan_key_p);
/**
 * @brief Set the ingress_tunnel_vni_ipv4_vxlan_key structure with packet_value
 *
 * @param [in,out] ingress_tunnel_vni_ipv4_vxlan_key_p - ingress_tunnel_vni_ipv4_vxlan_key
 * @param [in]     packet_value                        - packet_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_tunnel_vni_ipv4_vxlan_key_t_packet_value_set(ifcs_ingress_tunnel_vni_ipv4_vxlan_key_t *ingress_tunnel_vni_ipv4_vxlan_key_p, ifcs_uint32_t packet_value);

/**
 * @brief Get the ingress_tunnel_vni_ipv4_vxlan_key structure with packet_value
 *
 * @param [in,out] ingress_tunnel_vni_ipv4_vxlan_key_p - ingress_tunnel_vni_ipv4_vxlan_key
 * @param [in]     packet_value_p                      - packet_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_tunnel_vni_ipv4_vxlan_key_t_packet_value_get(ifcs_ingress_tunnel_vni_ipv4_vxlan_key_t *ingress_tunnel_vni_ipv4_vxlan_key_p, ifcs_uint32_t *packet_value_p);

/**
 * @brief Ingress tunnel vni map entry key match fields for IPv6 Vxlan tunnels
 */
typedef struct ifcs_ingress_tunnel_vni_ipv6_vxlan_key_s {

    ifcs_uint32_t packet_value;            ///< VxLAN VNID for IPv6 Vxlan tunnels
    ifcs_uint8_t  _dirty_packet_value : 1; ///< indicates if user has set packet_value
} ifcs_ingress_tunnel_vni_ipv6_vxlan_key_t;

/**
 * @brief Initialize the ingress_tunnel_vni_ipv6_vxlan_key structure
 *
 * @param [in,out] ingress_tunnel_vni_ipv6_vxlan_key_p - ingress_tunnel_vni_ipv6_vxlan_key
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_tunnel_vni_ipv6_vxlan_key_t_init(ifcs_ingress_tunnel_vni_ipv6_vxlan_key_t *ingress_tunnel_vni_ipv6_vxlan_key_p);
/**
 * @brief Set the ingress_tunnel_vni_ipv6_vxlan_key structure with packet_value
 *
 * @param [in,out] ingress_tunnel_vni_ipv6_vxlan_key_p - ingress_tunnel_vni_ipv6_vxlan_key
 * @param [in]     packet_value                        - packet_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_tunnel_vni_ipv6_vxlan_key_t_packet_value_set(ifcs_ingress_tunnel_vni_ipv6_vxlan_key_t *ingress_tunnel_vni_ipv6_vxlan_key_p, ifcs_uint32_t packet_value);

/**
 * @brief Get the ingress_tunnel_vni_ipv6_vxlan_key structure with packet_value
 *
 * @param [in,out] ingress_tunnel_vni_ipv6_vxlan_key_p - ingress_tunnel_vni_ipv6_vxlan_key
 * @param [in]     packet_value_p                      - packet_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ingress_tunnel_vni_ipv6_vxlan_key_t_packet_value_get(ifcs_ingress_tunnel_vni_ipv6_vxlan_key_t *ingress_tunnel_vni_ipv6_vxlan_key_p, ifcs_uint32_t *packet_value_p);

/**
 * @brief Ingress tunnel vni map entry key match fields for given key type
 */
typedef union ifcs_ingress_tunnel_vni_map_key_u {

    ifcs_ingress_tunnel_vni_ipv4_gre_key_t   ipv4_gre_key;   ///< key for IPv4 GRE tunnels
    ifcs_ingress_tunnel_vni_ipv6_gre_key_t   ipv6_gre_key;   ///< key for IPv6 GRE tunnels
    ifcs_ingress_tunnel_vni_ipv4_vxlan_key_t ipv4_vxlan_key; ///< key for IPv4 Vxlan tunnels
    ifcs_ingress_tunnel_vni_ipv6_vxlan_key_t ipv6_vxlan_key; ///< key for IPv6 Vxlan tunnels
} ifcs_ingress_tunnel_vni_map_key_t;

/**
 * @brief Egress tunnel vni map entry key match fields for IPv4 GRE tunnels
 */
typedef struct ifcs_egress_tunnel_vni_ipv4_gre_key_s {

    ifcs_handle_t l3vni;            ///< Device L3VNI for IPv4 GRE tunnels
    ifcs_uint8_t  _dirty_l3vni : 1; ///< indicates if user has set l3vni
} ifcs_egress_tunnel_vni_ipv4_gre_key_t;

/**
 * @brief Initialize the egress_tunnel_vni_ipv4_gre_key structure
 *
 * @param [in,out] egress_tunnel_vni_ipv4_gre_key_p - egress_tunnel_vni_ipv4_gre_key
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_tunnel_vni_ipv4_gre_key_t_init(ifcs_egress_tunnel_vni_ipv4_gre_key_t *egress_tunnel_vni_ipv4_gre_key_p);
/**
 * @brief Set the egress_tunnel_vni_ipv4_gre_key structure with l3vni
 *
 * @param [in,out] egress_tunnel_vni_ipv4_gre_key_p - egress_tunnel_vni_ipv4_gre_key
 * @param [in]     l3vni                            - l3vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_tunnel_vni_ipv4_gre_key_t_l3vni_set(ifcs_egress_tunnel_vni_ipv4_gre_key_t *egress_tunnel_vni_ipv4_gre_key_p, ifcs_handle_t l3vni);

/**
 * @brief Get the egress_tunnel_vni_ipv4_gre_key structure with l3vni
 *
 * @param [in,out] egress_tunnel_vni_ipv4_gre_key_p - egress_tunnel_vni_ipv4_gre_key
 * @param [in]     l3vni_p                          - l3vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_tunnel_vni_ipv4_gre_key_t_l3vni_get(ifcs_egress_tunnel_vni_ipv4_gre_key_t *egress_tunnel_vni_ipv4_gre_key_p, ifcs_handle_t *l3vni_p);

/**
 * @brief Egress tunnel vni map entry key match fields for IPv6 GRE tunnels
 */
typedef struct ifcs_egress_tunnel_vni_ipv6_gre_key_s {

    ifcs_handle_t l3vni;            ///< Device L3VNI for IPv6 GRE tunnels
    ifcs_uint8_t  _dirty_l3vni : 1; ///< indicates if user has set l3vni
} ifcs_egress_tunnel_vni_ipv6_gre_key_t;

/**
 * @brief Initialize the egress_tunnel_vni_ipv6_gre_key structure
 *
 * @param [in,out] egress_tunnel_vni_ipv6_gre_key_p - egress_tunnel_vni_ipv6_gre_key
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_tunnel_vni_ipv6_gre_key_t_init(ifcs_egress_tunnel_vni_ipv6_gre_key_t *egress_tunnel_vni_ipv6_gre_key_p);
/**
 * @brief Set the egress_tunnel_vni_ipv6_gre_key structure with l3vni
 *
 * @param [in,out] egress_tunnel_vni_ipv6_gre_key_p - egress_tunnel_vni_ipv6_gre_key
 * @param [in]     l3vni                            - l3vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_tunnel_vni_ipv6_gre_key_t_l3vni_set(ifcs_egress_tunnel_vni_ipv6_gre_key_t *egress_tunnel_vni_ipv6_gre_key_p, ifcs_handle_t l3vni);

/**
 * @brief Get the egress_tunnel_vni_ipv6_gre_key structure with l3vni
 *
 * @param [in,out] egress_tunnel_vni_ipv6_gre_key_p - egress_tunnel_vni_ipv6_gre_key
 * @param [in]     l3vni_p                          - l3vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_tunnel_vni_ipv6_gre_key_t_l3vni_get(ifcs_egress_tunnel_vni_ipv6_gre_key_t *egress_tunnel_vni_ipv6_gre_key_p, ifcs_handle_t *l3vni_p);

/**
 * @brief Egress tunnel vni map entry key match fields for IPv4 VxLAN tunnels
 */
typedef struct ifcs_egress_tunnel_vni_ipv4_vxlan_key_s {

    ifcs_handle_t l2vni;            ///< Device L2VNI for IPv4 VxLAN tunnels
    ifcs_uint8_t  _dirty_l2vni : 1; ///< indicates if user has set l2vni
} ifcs_egress_tunnel_vni_ipv4_vxlan_key_t;

/**
 * @brief Initialize the egress_tunnel_vni_ipv4_vxlan_key structure
 *
 * @param [in,out] egress_tunnel_vni_ipv4_vxlan_key_p - egress_tunnel_vni_ipv4_vxlan_key
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_tunnel_vni_ipv4_vxlan_key_t_init(ifcs_egress_tunnel_vni_ipv4_vxlan_key_t *egress_tunnel_vni_ipv4_vxlan_key_p);
/**
 * @brief Set the egress_tunnel_vni_ipv4_vxlan_key structure with l2vni
 *
 * @param [in,out] egress_tunnel_vni_ipv4_vxlan_key_p - egress_tunnel_vni_ipv4_vxlan_key
 * @param [in]     l2vni                              - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_tunnel_vni_ipv4_vxlan_key_t_l2vni_set(ifcs_egress_tunnel_vni_ipv4_vxlan_key_t *egress_tunnel_vni_ipv4_vxlan_key_p, ifcs_handle_t l2vni);

/**
 * @brief Get the egress_tunnel_vni_ipv4_vxlan_key structure with l2vni
 *
 * @param [in,out] egress_tunnel_vni_ipv4_vxlan_key_p - egress_tunnel_vni_ipv4_vxlan_key
 * @param [in]     l2vni_p                            - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_tunnel_vni_ipv4_vxlan_key_t_l2vni_get(ifcs_egress_tunnel_vni_ipv4_vxlan_key_t *egress_tunnel_vni_ipv4_vxlan_key_p, ifcs_handle_t *l2vni_p);

/**
 * @brief Egress tunnel vni map entry key match fields for IPv6 VxLAN tunnels
 */
typedef struct ifcs_egress_tunnel_vni_ipv6_vxlan_key_s {

    ifcs_handle_t l2vni;            ///< Device L2VNI for IPv6 VxLAN tunnels
    ifcs_uint8_t  _dirty_l2vni : 1; ///< indicates if user has set l2vni
} ifcs_egress_tunnel_vni_ipv6_vxlan_key_t;

/**
 * @brief Initialize the egress_tunnel_vni_ipv6_vxlan_key structure
 *
 * @param [in,out] egress_tunnel_vni_ipv6_vxlan_key_p - egress_tunnel_vni_ipv6_vxlan_key
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_tunnel_vni_ipv6_vxlan_key_t_init(ifcs_egress_tunnel_vni_ipv6_vxlan_key_t *egress_tunnel_vni_ipv6_vxlan_key_p);
/**
 * @brief Set the egress_tunnel_vni_ipv6_vxlan_key structure with l2vni
 *
 * @param [in,out] egress_tunnel_vni_ipv6_vxlan_key_p - egress_tunnel_vni_ipv6_vxlan_key
 * @param [in]     l2vni                              - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_tunnel_vni_ipv6_vxlan_key_t_l2vni_set(ifcs_egress_tunnel_vni_ipv6_vxlan_key_t *egress_tunnel_vni_ipv6_vxlan_key_p, ifcs_handle_t l2vni);

/**
 * @brief Get the egress_tunnel_vni_ipv6_vxlan_key structure with l2vni
 *
 * @param [in,out] egress_tunnel_vni_ipv6_vxlan_key_p - egress_tunnel_vni_ipv6_vxlan_key
 * @param [in]     l2vni_p                            - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_egress_tunnel_vni_ipv6_vxlan_key_t_l2vni_get(ifcs_egress_tunnel_vni_ipv6_vxlan_key_t *egress_tunnel_vni_ipv6_vxlan_key_p, ifcs_handle_t *l2vni_p);

/**
 * @brief Egress vni to tunnel map entry key match fields for given key type
 */
typedef union ifcs_egress_tunnel_vni_map_key_u {

    ifcs_egress_tunnel_vni_ipv4_gre_key_t   ipv4_gre_key;   ///< key for IPv4 GRE tunnels
    ifcs_egress_tunnel_vni_ipv6_gre_key_t   ipv6_gre_key;   ///< key for IPv6 GRE tunnels
    ifcs_egress_tunnel_vni_ipv4_vxlan_key_t ipv4_vxlan_key; ///< key for IPv4 Vxlan tunnels
    ifcs_egress_tunnel_vni_ipv6_vxlan_key_t ipv6_vxlan_key; ///< key for IPv6 Vxlan tunnels
} ifcs_egress_tunnel_vni_map_key_t;

/**
 * @brief Route entry with keys IP destination only (global routes)
 */
typedef struct ifcs_route_entry_key_ip_dest_only_s {

    ifcs_ip_prefix_t ip_dest;            ///< Destination IP/Mask
    ifcs_uint8_t     _dirty_ip_dest : 1; ///< indicates if user has set ip_dest
} ifcs_route_entry_key_ip_dest_only_t;

/**
 * @brief Initialize the route_entry_key_ip_dest_only structure
 *
 * @param [in,out] route_entry_key_ip_dest_only_p - route_entry_key_ip_dest_only
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_route_entry_key_ip_dest_only_t_init(ifcs_route_entry_key_ip_dest_only_t *route_entry_key_ip_dest_only_p);
/**
 * @brief Set the route_entry_key_ip_dest_only structure with ip_dest
 *
 * @param [in,out] route_entry_key_ip_dest_only_p - route_entry_key_ip_dest_only
 * @param [in]     ip_dest_p                      - ip_dest
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_route_entry_key_ip_dest_only_t_ip_dest_set(ifcs_route_entry_key_ip_dest_only_t *route_entry_key_ip_dest_only_p, ifcs_ip_prefix_t *ip_dest_p);

/**
 * @brief Get the route_entry_key_ip_dest_only structure with ip_dest
 *
 * @param [in,out] route_entry_key_ip_dest_only_p - route_entry_key_ip_dest_only
 * @param [in]     ip_dest_p                      - ip_dest
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_route_entry_key_ip_dest_only_t_ip_dest_get(ifcs_route_entry_key_ip_dest_only_t *route_entry_key_ip_dest_only_p, ifcs_ip_prefix_t *ip_dest_p);

/**
 * @brief Route entry with keys IP destination, L3 VNI
 */
typedef struct ifcs_route_entry_key_ip_dest_l3vni_s {

    ifcs_ip_prefix_t ip_dest;            ///< Destination IP/Mask
    ifcs_handle_t    l3vni;              ///< L3VNI
    ifcs_uint8_t     _dirty_ip_dest : 1; ///< indicates if user has set ip_dest
    ifcs_uint8_t     _dirty_l3vni : 1;   ///< indicates if user has set l3vni
} ifcs_route_entry_key_ip_dest_l3vni_t;

/**
 * @brief Initialize the route_entry_key_ip_dest_l3vni structure
 *
 * @param [in,out] route_entry_key_ip_dest_l3vni_p - route_entry_key_ip_dest_l3vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_route_entry_key_ip_dest_l3vni_t_init(ifcs_route_entry_key_ip_dest_l3vni_t *route_entry_key_ip_dest_l3vni_p);
/**
 * @brief Set the route_entry_key_ip_dest_l3vni structure with ip_dest
 *
 * @param [in,out] route_entry_key_ip_dest_l3vni_p - route_entry_key_ip_dest_l3vni
 * @param [in]     ip_dest_p                       - ip_dest
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_route_entry_key_ip_dest_l3vni_t_ip_dest_set(ifcs_route_entry_key_ip_dest_l3vni_t *route_entry_key_ip_dest_l3vni_p, ifcs_ip_prefix_t *ip_dest_p);

/**
 * @brief Get the route_entry_key_ip_dest_l3vni structure with ip_dest
 *
 * @param [in,out] route_entry_key_ip_dest_l3vni_p - route_entry_key_ip_dest_l3vni
 * @param [in]     ip_dest_p                       - ip_dest
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_route_entry_key_ip_dest_l3vni_t_ip_dest_get(ifcs_route_entry_key_ip_dest_l3vni_t *route_entry_key_ip_dest_l3vni_p, ifcs_ip_prefix_t *ip_dest_p);

/**
 * @brief Set the route_entry_key_ip_dest_l3vni structure with l3vni
 *
 * @param [in,out] route_entry_key_ip_dest_l3vni_p - route_entry_key_ip_dest_l3vni
 * @param [in]     l3vni                           - l3vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_route_entry_key_ip_dest_l3vni_t_l3vni_set(ifcs_route_entry_key_ip_dest_l3vni_t *route_entry_key_ip_dest_l3vni_p, ifcs_handle_t l3vni);

/**
 * @brief Get the route_entry_key_ip_dest_l3vni structure with l3vni
 *
 * @param [in,out] route_entry_key_ip_dest_l3vni_p - route_entry_key_ip_dest_l3vni
 * @param [in]     l3vni_p                         - l3vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_route_entry_key_ip_dest_l3vni_t_l3vni_get(ifcs_route_entry_key_ip_dest_l3vni_t *route_entry_key_ip_dest_l3vni_p, ifcs_handle_t *l3vni_p);

/**
 * @brief L2Entry with keys Source IP,Group IP, L2vni
 */
typedef struct ifcs_l2_entry_key_ip_sg_l2vni_s {

    ifcs_ip_prefix_t source;            ///< Multicast sender IP
    ifcs_ip_prefix_t group;             ///< Multicast group IP
    ifcs_handle_t    l2vni;             ///< L2 Vni
    ifcs_uint8_t     _dirty_source : 1; ///< indicates if user has set source
    ifcs_uint8_t     _dirty_group : 1;  ///< indicates if user has set group
    ifcs_uint8_t     _dirty_l2vni : 1;  ///< indicates if user has set l2vni
} ifcs_l2_entry_key_ip_sg_l2vni_t;

/**
 * @brief Initialize the l2_entry_key_ip_sg_l2vni structure
 *
 * @param [in,out] l2_entry_key_ip_sg_l2vni_p - l2_entry_key_ip_sg_l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_ip_sg_l2vni_t_init(ifcs_l2_entry_key_ip_sg_l2vni_t *l2_entry_key_ip_sg_l2vni_p);
/**
 * @brief Set the l2_entry_key_ip_sg_l2vni structure with source
 *
 * @param [in,out] l2_entry_key_ip_sg_l2vni_p - l2_entry_key_ip_sg_l2vni
 * @param [in]     source_p                   - source
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_ip_sg_l2vni_t_source_set(ifcs_l2_entry_key_ip_sg_l2vni_t *l2_entry_key_ip_sg_l2vni_p, ifcs_ip_prefix_t *source_p);

/**
 * @brief Get the l2_entry_key_ip_sg_l2vni structure with source
 *
 * @param [in,out] l2_entry_key_ip_sg_l2vni_p - l2_entry_key_ip_sg_l2vni
 * @param [in]     source_p                   - source
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_ip_sg_l2vni_t_source_get(ifcs_l2_entry_key_ip_sg_l2vni_t *l2_entry_key_ip_sg_l2vni_p, ifcs_ip_prefix_t *source_p);

/**
 * @brief Set the l2_entry_key_ip_sg_l2vni structure with group
 *
 * @param [in,out] l2_entry_key_ip_sg_l2vni_p - l2_entry_key_ip_sg_l2vni
 * @param [in]     group_p                    - group
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_ip_sg_l2vni_t_group_set(ifcs_l2_entry_key_ip_sg_l2vni_t *l2_entry_key_ip_sg_l2vni_p, ifcs_ip_prefix_t *group_p);

/**
 * @brief Get the l2_entry_key_ip_sg_l2vni structure with group
 *
 * @param [in,out] l2_entry_key_ip_sg_l2vni_p - l2_entry_key_ip_sg_l2vni
 * @param [in]     group_p                    - group
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_ip_sg_l2vni_t_group_get(ifcs_l2_entry_key_ip_sg_l2vni_t *l2_entry_key_ip_sg_l2vni_p, ifcs_ip_prefix_t *group_p);

/**
 * @brief Set the l2_entry_key_ip_sg_l2vni structure with l2vni
 *
 * @param [in,out] l2_entry_key_ip_sg_l2vni_p - l2_entry_key_ip_sg_l2vni
 * @param [in]     l2vni                      - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_ip_sg_l2vni_t_l2vni_set(ifcs_l2_entry_key_ip_sg_l2vni_t *l2_entry_key_ip_sg_l2vni_p, ifcs_handle_t l2vni);

/**
 * @brief Get the l2_entry_key_ip_sg_l2vni structure with l2vni
 *
 * @param [in,out] l2_entry_key_ip_sg_l2vni_p - l2_entry_key_ip_sg_l2vni
 * @param [in]     l2vni_p                    - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_ip_sg_l2vni_t_l2vni_get(ifcs_l2_entry_key_ip_sg_l2vni_t *l2_entry_key_ip_sg_l2vni_p, ifcs_handle_t *l2vni_p);

/**
 * @brief L2Entry with keys Group IP, L2vni
 */
typedef struct ifcs_l2_entry_key_ip_starg_l2vni_s {

    ifcs_ip_prefix_t group;            ///< Multicast group IP
    ifcs_handle_t    l2vni;            ///< L2 Vni
    ifcs_uint8_t     _dirty_group : 1; ///< indicates if user has set group
    ifcs_uint8_t     _dirty_l2vni : 1; ///< indicates if user has set l2vni
} ifcs_l2_entry_key_ip_starg_l2vni_t;

/**
 * @brief Initialize the l2_entry_key_ip_starg_l2vni structure
 *
 * @param [in,out] l2_entry_key_ip_starg_l2vni_p - l2_entry_key_ip_starg_l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_ip_starg_l2vni_t_init(ifcs_l2_entry_key_ip_starg_l2vni_t *l2_entry_key_ip_starg_l2vni_p);
/**
 * @brief Set the l2_entry_key_ip_starg_l2vni structure with group
 *
 * @param [in,out] l2_entry_key_ip_starg_l2vni_p - l2_entry_key_ip_starg_l2vni
 * @param [in]     group_p                       - group
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_ip_starg_l2vni_t_group_set(ifcs_l2_entry_key_ip_starg_l2vni_t *l2_entry_key_ip_starg_l2vni_p, ifcs_ip_prefix_t *group_p);

/**
 * @brief Get the l2_entry_key_ip_starg_l2vni structure with group
 *
 * @param [in,out] l2_entry_key_ip_starg_l2vni_p - l2_entry_key_ip_starg_l2vni
 * @param [in]     group_p                       - group
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_ip_starg_l2vni_t_group_get(ifcs_l2_entry_key_ip_starg_l2vni_t *l2_entry_key_ip_starg_l2vni_p, ifcs_ip_prefix_t *group_p);

/**
 * @brief Set the l2_entry_key_ip_starg_l2vni structure with l2vni
 *
 * @param [in,out] l2_entry_key_ip_starg_l2vni_p - l2_entry_key_ip_starg_l2vni
 * @param [in]     l2vni                         - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_ip_starg_l2vni_t_l2vni_set(ifcs_l2_entry_key_ip_starg_l2vni_t *l2_entry_key_ip_starg_l2vni_p, ifcs_handle_t l2vni);

/**
 * @brief Get the l2_entry_key_ip_starg_l2vni structure with l2vni
 *
 * @param [in,out] l2_entry_key_ip_starg_l2vni_p - l2_entry_key_ip_starg_l2vni
 * @param [in]     l2vni_p                       - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_ip_starg_l2vni_t_l2vni_get(ifcs_l2_entry_key_ip_starg_l2vni_t *l2_entry_key_ip_starg_l2vni_p, ifcs_handle_t *l2vni_p);

/**
 * @brief L2Entry with keys Mac, L2vni
 */
typedef struct ifcs_l2_entry_key_mac_l2vni_s {

    ifcs_mac_t    mac_addr;            ///< Mac address
    ifcs_handle_t l2vni;               ///< L2 Vni
    ifcs_uint8_t  _dirty_mac_addr : 1; ///< indicates if user has set mac_addr
    ifcs_uint8_t  _dirty_l2vni : 1;    ///< indicates if user has set l2vni
} ifcs_l2_entry_key_mac_l2vni_t;

/**
 * @brief Initialize the l2_entry_key_mac_l2vni structure
 *
 * @param [in,out] l2_entry_key_mac_l2vni_p - l2_entry_key_mac_l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2vni_t_init(ifcs_l2_entry_key_mac_l2vni_t *l2_entry_key_mac_l2vni_p);
/**
 * @brief Set the l2_entry_key_mac_l2vni structure with mac_addr
 *
 * @param [in,out] l2_entry_key_mac_l2vni_p - l2_entry_key_mac_l2vni
 * @param [in]     mac_addr_p               - mac_addr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2vni_t_mac_addr_set(ifcs_l2_entry_key_mac_l2vni_t *l2_entry_key_mac_l2vni_p, ifcs_mac_t *mac_addr_p);

/**
 * @brief Get the l2_entry_key_mac_l2vni structure with mac_addr
 *
 * @param [in,out] l2_entry_key_mac_l2vni_p - l2_entry_key_mac_l2vni
 * @param [in]     mac_addr_p               - mac_addr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2vni_t_mac_addr_get(ifcs_l2_entry_key_mac_l2vni_t *l2_entry_key_mac_l2vni_p, ifcs_mac_t *mac_addr_p);

/**
 * @brief Set the l2_entry_key_mac_l2vni structure with l2vni
 *
 * @param [in,out] l2_entry_key_mac_l2vni_p - l2_entry_key_mac_l2vni
 * @param [in]     l2vni                    - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2vni_t_l2vni_set(ifcs_l2_entry_key_mac_l2vni_t *l2_entry_key_mac_l2vni_p, ifcs_handle_t l2vni);

/**
 * @brief Get the l2_entry_key_mac_l2vni structure with l2vni
 *
 * @param [in,out] l2_entry_key_mac_l2vni_p - l2_entry_key_mac_l2vni
 * @param [in]     l2vni_p                  - l2vni
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2vni_t_l2vni_get(ifcs_l2_entry_key_mac_l2vni_t *l2_entry_key_mac_l2vni_p, ifcs_handle_t *l2vni_p);

/**
 * @brief L2Entry with keys Mac, mask
 */
typedef struct ifcs_l2_entry_key_mac_only_s {

    ifcs_mac_t   mac_addr;            ///< Mac address
    ifcs_mac_t   mac_mask;            ///< Prefix style mask
    ifcs_uint8_t _dirty_mac_addr : 1; ///< indicates if user has set mac_addr
    ifcs_uint8_t _dirty_mac_mask : 1; ///< indicates if user has set mac_mask
} ifcs_l2_entry_key_mac_only_t;

/**
 * @brief Initialize the l2_entry_key_mac_only structure
 *
 * @param [in,out] l2_entry_key_mac_only_p - l2_entry_key_mac_only
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_only_t_init(ifcs_l2_entry_key_mac_only_t *l2_entry_key_mac_only_p);
/**
 * @brief Set the l2_entry_key_mac_only structure with mac_addr
 *
 * @param [in,out] l2_entry_key_mac_only_p - l2_entry_key_mac_only
 * @param [in]     mac_addr_p              - mac_addr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_only_t_mac_addr_set(ifcs_l2_entry_key_mac_only_t *l2_entry_key_mac_only_p, ifcs_mac_t *mac_addr_p);

/**
 * @brief Get the l2_entry_key_mac_only structure with mac_addr
 *
 * @param [in,out] l2_entry_key_mac_only_p - l2_entry_key_mac_only
 * @param [in]     mac_addr_p              - mac_addr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_only_t_mac_addr_get(ifcs_l2_entry_key_mac_only_t *l2_entry_key_mac_only_p, ifcs_mac_t *mac_addr_p);

/**
 * @brief Set the l2_entry_key_mac_only structure with mac_mask
 *
 * @param [in,out] l2_entry_key_mac_only_p - l2_entry_key_mac_only
 * @param [in]     mac_mask_p              - mac_mask
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_only_t_mac_mask_set(ifcs_l2_entry_key_mac_only_t *l2_entry_key_mac_only_p, ifcs_mac_t *mac_mask_p);

/**
 * @brief Get the l2_entry_key_mac_only structure with mac_mask
 *
 * @param [in,out] l2_entry_key_mac_only_p - l2_entry_key_mac_only
 * @param [in]     mac_mask_p              - mac_mask
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_only_t_mac_mask_get(ifcs_l2_entry_key_mac_only_t *l2_entry_key_mac_only_p, ifcs_mac_t *mac_mask_p);

/**
 * @brief L2Entry with keys Mac, Layer 2 ingress interface (sysport/lag/L2 tunnel interface), Ingress L2 Vni value, and corresponding masks
 */
typedef struct ifcs_l2_entry_key_mac_l2iif_l2vni_id_s {

    ifcs_mac_t    mac_addr;                 ///< Mac address
    ifcs_mac_t    mac_mask;                 ///< Prefix style Mac mask
    ifcs_handle_t l2iif;                    ///< Layer 2 ingress interface - sysport/lag/L2 tunnel interface handle. Use IFCS_NULL_HANDLE when not specifying an interface
    ifcs_handle_t l2iif_mask;               ///< Layer 2 ingress interface mask. Value field of the handle is 0 (match all) or all bit set to 1 (match exact). Match all handle examples: IFCS_NULL_HANDLE, IFCS_HANDLE_SYSPORT(0). Match exact handle example: IFCS_HANDLE_SYSPORT(IFCS_HANDLE_VALUE_MAX)
    ifcs_uint16_t l2vni_id;                 ///< Ingress L2 Vni value. Value range is 0 to 8191
    ifcs_uint16_t l2vni_id_mask;            ///< Ingress L2 Vni value mask. Value range is 0 to 8191. Mask with holes (not all 1s together n left shifted) is not valid
    ifcs_uint8_t  _dirty_mac_addr : 1;      ///< indicates if user has set mac_addr
    ifcs_uint8_t  _dirty_mac_mask : 1;      ///< indicates if user has set mac_mask
    ifcs_uint8_t  _dirty_l2iif : 1;         ///< indicates if user has set l2iif
    ifcs_uint8_t  _dirty_l2iif_mask : 1;    ///< indicates if user has set l2iif_mask
    ifcs_uint8_t  _dirty_l2vni_id : 1;      ///< indicates if user has set l2vni_id
    ifcs_uint8_t  _dirty_l2vni_id_mask : 1; ///< indicates if user has set l2vni_id_mask
} ifcs_l2_entry_key_mac_l2iif_l2vni_id_t;

/**
 * @brief Initialize the l2_entry_key_mac_l2iif_l2vni_id structure
 *
 * @param [in,out] l2_entry_key_mac_l2iif_l2vni_id_p - l2_entry_key_mac_l2iif_l2vni_id
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2iif_l2vni_id_t_init(ifcs_l2_entry_key_mac_l2iif_l2vni_id_t *l2_entry_key_mac_l2iif_l2vni_id_p);
/**
 * @brief Set the l2_entry_key_mac_l2iif_l2vni_id structure with mac_addr
 *
 * @param [in,out] l2_entry_key_mac_l2iif_l2vni_id_p - l2_entry_key_mac_l2iif_l2vni_id
 * @param [in]     mac_addr_p                        - mac_addr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2iif_l2vni_id_t_mac_addr_set(ifcs_l2_entry_key_mac_l2iif_l2vni_id_t *l2_entry_key_mac_l2iif_l2vni_id_p, ifcs_mac_t *mac_addr_p);

/**
 * @brief Get the l2_entry_key_mac_l2iif_l2vni_id structure with mac_addr
 *
 * @param [in,out] l2_entry_key_mac_l2iif_l2vni_id_p - l2_entry_key_mac_l2iif_l2vni_id
 * @param [in]     mac_addr_p                        - mac_addr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2iif_l2vni_id_t_mac_addr_get(ifcs_l2_entry_key_mac_l2iif_l2vni_id_t *l2_entry_key_mac_l2iif_l2vni_id_p, ifcs_mac_t *mac_addr_p);

/**
 * @brief Set the l2_entry_key_mac_l2iif_l2vni_id structure with mac_mask
 *
 * @param [in,out] l2_entry_key_mac_l2iif_l2vni_id_p - l2_entry_key_mac_l2iif_l2vni_id
 * @param [in]     mac_mask_p                        - mac_mask
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2iif_l2vni_id_t_mac_mask_set(ifcs_l2_entry_key_mac_l2iif_l2vni_id_t *l2_entry_key_mac_l2iif_l2vni_id_p, ifcs_mac_t *mac_mask_p);

/**
 * @brief Get the l2_entry_key_mac_l2iif_l2vni_id structure with mac_mask
 *
 * @param [in,out] l2_entry_key_mac_l2iif_l2vni_id_p - l2_entry_key_mac_l2iif_l2vni_id
 * @param [in]     mac_mask_p                        - mac_mask
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2iif_l2vni_id_t_mac_mask_get(ifcs_l2_entry_key_mac_l2iif_l2vni_id_t *l2_entry_key_mac_l2iif_l2vni_id_p, ifcs_mac_t *mac_mask_p);

/**
 * @brief Set the l2_entry_key_mac_l2iif_l2vni_id structure with l2iif
 *
 * @param [in,out] l2_entry_key_mac_l2iif_l2vni_id_p - l2_entry_key_mac_l2iif_l2vni_id
 * @param [in]     l2iif                             - l2iif
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2iif_l2vni_id_t_l2iif_set(ifcs_l2_entry_key_mac_l2iif_l2vni_id_t *l2_entry_key_mac_l2iif_l2vni_id_p, ifcs_handle_t l2iif);

/**
 * @brief Get the l2_entry_key_mac_l2iif_l2vni_id structure with l2iif
 *
 * @param [in,out] l2_entry_key_mac_l2iif_l2vni_id_p - l2_entry_key_mac_l2iif_l2vni_id
 * @param [in]     l2iif_p                           - l2iif
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2iif_l2vni_id_t_l2iif_get(ifcs_l2_entry_key_mac_l2iif_l2vni_id_t *l2_entry_key_mac_l2iif_l2vni_id_p, ifcs_handle_t *l2iif_p);

/**
 * @brief Set the l2_entry_key_mac_l2iif_l2vni_id structure with l2iif_mask
 *
 * @param [in,out] l2_entry_key_mac_l2iif_l2vni_id_p - l2_entry_key_mac_l2iif_l2vni_id
 * @param [in]     l2iif_mask                        - l2iif_mask
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2iif_l2vni_id_t_l2iif_mask_set(ifcs_l2_entry_key_mac_l2iif_l2vni_id_t *l2_entry_key_mac_l2iif_l2vni_id_p, ifcs_handle_t l2iif_mask);

/**
 * @brief Get the l2_entry_key_mac_l2iif_l2vni_id structure with l2iif_mask
 *
 * @param [in,out] l2_entry_key_mac_l2iif_l2vni_id_p - l2_entry_key_mac_l2iif_l2vni_id
 * @param [in]     l2iif_mask_p                      - l2iif_mask
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2iif_l2vni_id_t_l2iif_mask_get(ifcs_l2_entry_key_mac_l2iif_l2vni_id_t *l2_entry_key_mac_l2iif_l2vni_id_p, ifcs_handle_t *l2iif_mask_p);

/**
 * @brief Set the l2_entry_key_mac_l2iif_l2vni_id structure with l2vni_id
 *
 * @param [in,out] l2_entry_key_mac_l2iif_l2vni_id_p - l2_entry_key_mac_l2iif_l2vni_id
 * @param [in]     l2vni_id                          - l2vni_id
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2iif_l2vni_id_t_l2vni_id_set(ifcs_l2_entry_key_mac_l2iif_l2vni_id_t *l2_entry_key_mac_l2iif_l2vni_id_p, ifcs_uint16_t l2vni_id);

/**
 * @brief Get the l2_entry_key_mac_l2iif_l2vni_id structure with l2vni_id
 *
 * @param [in,out] l2_entry_key_mac_l2iif_l2vni_id_p - l2_entry_key_mac_l2iif_l2vni_id
 * @param [in]     l2vni_id_p                        - l2vni_id
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2iif_l2vni_id_t_l2vni_id_get(ifcs_l2_entry_key_mac_l2iif_l2vni_id_t *l2_entry_key_mac_l2iif_l2vni_id_p, ifcs_uint16_t *l2vni_id_p);

/**
 * @brief Set the l2_entry_key_mac_l2iif_l2vni_id structure with l2vni_id_mask
 *
 * @param [in,out] l2_entry_key_mac_l2iif_l2vni_id_p - l2_entry_key_mac_l2iif_l2vni_id
 * @param [in]     l2vni_id_mask                     - l2vni_id_mask
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2iif_l2vni_id_t_l2vni_id_mask_set(ifcs_l2_entry_key_mac_l2iif_l2vni_id_t *l2_entry_key_mac_l2iif_l2vni_id_p, ifcs_uint16_t l2vni_id_mask);

/**
 * @brief Get the l2_entry_key_mac_l2iif_l2vni_id structure with l2vni_id_mask
 *
 * @param [in,out] l2_entry_key_mac_l2iif_l2vni_id_p - l2_entry_key_mac_l2iif_l2vni_id
 * @param [in]     l2vni_id_mask_p                   - l2vni_id_mask
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_l2_entry_key_mac_l2iif_l2vni_id_t_l2vni_id_mask_get(ifcs_l2_entry_key_mac_l2iif_l2vni_id_t *l2_entry_key_mac_l2iif_l2vni_id_p, ifcs_uint16_t *l2vni_id_mask_p);

/**
 * @brief Match in
 */
typedef struct ifcs_fpf_match_info_s {

    ifcs_fpf_match_type_t type;             ///< Type of match
    ifcs_uint32_t         value;            ///< Value
    ifcs_uint32_t         mask;             ///< Mask
    ifcs_uint8_t          _dirty_type : 1;  ///< indicates if user has set type
    ifcs_uint8_t          _dirty_value : 1; ///< indicates if user has set value
    ifcs_uint8_t          _dirty_mask : 1;  ///< indicates if user has set mask
} ifcs_fpf_match_info_t;

/**
 * @brief Initialize the fpf_match_info structure
 *
 * @param [in,out] fpf_match_info_p - fpf_match_info
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fpf_match_info_t_init(ifcs_fpf_match_info_t *fpf_match_info_p);
/**
 * @brief Set the fpf_match_info structure with type
 *
 * @param [in,out] fpf_match_info_p - fpf_match_info
 * @param [in]     type             - type
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fpf_match_info_t_type_set(ifcs_fpf_match_info_t *fpf_match_info_p, ifcs_fpf_match_type_t type);

/**
 * @brief Get the fpf_match_info structure with type
 *
 * @param [in,out] fpf_match_info_p - fpf_match_info
 * @param [in]     type_p           - type
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fpf_match_info_t_type_get(ifcs_fpf_match_info_t *fpf_match_info_p, ifcs_fpf_match_type_t *type_p);

/**
 * @brief Set the fpf_match_info structure with value
 *
 * @param [in,out] fpf_match_info_p - fpf_match_info
 * @param [in]     value            - value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fpf_match_info_t_value_set(ifcs_fpf_match_info_t *fpf_match_info_p, ifcs_uint32_t value);

/**
 * @brief Get the fpf_match_info structure with value
 *
 * @param [in,out] fpf_match_info_p - fpf_match_info
 * @param [in]     value_p          - value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fpf_match_info_t_value_get(ifcs_fpf_match_info_t *fpf_match_info_p, ifcs_uint32_t *value_p);

/**
 * @brief Set the fpf_match_info structure with mask
 *
 * @param [in,out] fpf_match_info_p - fpf_match_info
 * @param [in]     mask             - mask
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fpf_match_info_t_mask_set(ifcs_fpf_match_info_t *fpf_match_info_p, ifcs_uint32_t mask);

/**
 * @brief Get the fpf_match_info structure with mask
 *
 * @param [in,out] fpf_match_info_p - fpf_match_info
 * @param [in]     mask_p           - mask
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fpf_match_info_t_mask_get(ifcs_fpf_match_info_t *fpf_match_info_p, ifcs_uint32_t *mask_p);

/**
 * @brief Match conditions to extract the packet fields
 */
typedef struct ifcs_fpf_match_list_s {

    uint32_t               count; ///< count
    ifcs_fpf_match_info_t *arr;   ///< Match conditions to extract the packet fields
} ifcs_fpf_match_list_t;

/**
 * @brief FPF extration command information
 */
typedef struct ifcs_fpf_extraction_cmd_info_s {

    ifcs_fpf_field_t     field;             ///< Field Number
    ifcs_fpf_base_type_t base;              ///< Packet marker from where to extract the fields from
    ifcs_uint32_t        offset;            ///< Offset from the base (must be multiple of 2)
    ifcs_uint8_t         _dirty_field : 1;  ///< indicates if user has set field
    ifcs_uint8_t         _dirty_base : 1;   ///< indicates if user has set base
    ifcs_uint8_t         _dirty_offset : 1; ///< indicates if user has set offset
} ifcs_fpf_extraction_cmd_info_t;

/**
 * @brief Initialize the fpf_extraction_cmd_info structure
 *
 * @param [in,out] fpf_extraction_cmd_info_p - fpf_extraction_cmd_info
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fpf_extraction_cmd_info_t_init(ifcs_fpf_extraction_cmd_info_t *fpf_extraction_cmd_info_p);
/**
 * @brief Set the fpf_extraction_cmd_info structure with field
 *
 * @param [in,out] fpf_extraction_cmd_info_p - fpf_extraction_cmd_info
 * @param [in]     field                     - field
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fpf_extraction_cmd_info_t_field_set(ifcs_fpf_extraction_cmd_info_t *fpf_extraction_cmd_info_p, ifcs_fpf_field_t field);

/**
 * @brief Get the fpf_extraction_cmd_info structure with field
 *
 * @param [in,out] fpf_extraction_cmd_info_p - fpf_extraction_cmd_info
 * @param [in]     field_p                   - field
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fpf_extraction_cmd_info_t_field_get(ifcs_fpf_extraction_cmd_info_t *fpf_extraction_cmd_info_p, ifcs_fpf_field_t *field_p);

/**
 * @brief Set the fpf_extraction_cmd_info structure with base
 *
 * @param [in,out] fpf_extraction_cmd_info_p - fpf_extraction_cmd_info
 * @param [in]     base                      - base
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fpf_extraction_cmd_info_t_base_set(ifcs_fpf_extraction_cmd_info_t *fpf_extraction_cmd_info_p, ifcs_fpf_base_type_t base);

/**
 * @brief Get the fpf_extraction_cmd_info structure with base
 *
 * @param [in,out] fpf_extraction_cmd_info_p - fpf_extraction_cmd_info
 * @param [in]     base_p                    - base
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fpf_extraction_cmd_info_t_base_get(ifcs_fpf_extraction_cmd_info_t *fpf_extraction_cmd_info_p, ifcs_fpf_base_type_t *base_p);

/**
 * @brief Set the fpf_extraction_cmd_info structure with offset
 *
 * @param [in,out] fpf_extraction_cmd_info_p - fpf_extraction_cmd_info
 * @param [in]     offset                    - offset
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fpf_extraction_cmd_info_t_offset_set(ifcs_fpf_extraction_cmd_info_t *fpf_extraction_cmd_info_p, ifcs_uint32_t offset);

/**
 * @brief Get the fpf_extraction_cmd_info structure with offset
 *
 * @param [in,out] fpf_extraction_cmd_info_p - fpf_extraction_cmd_info
 * @param [in]     offset_p                  - offset
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_fpf_extraction_cmd_info_t_offset_get(ifcs_fpf_extraction_cmd_info_t *fpf_extraction_cmd_info_p, ifcs_uint32_t *offset_p);

/**
 * @brief Commands to extract the fields
 */
typedef struct ifcs_fpf_extraction_cmd_list_s {

    uint32_t                        count; ///< count
    ifcs_fpf_extraction_cmd_info_t *arr;   ///< Commands to extract the fields
} ifcs_fpf_extraction_cmd_list_t;

/**
 * @brief List of devport Auto-Neg base page tech ability
 */
typedef struct ifcs_devport_an_bp_tech_ability_list_s {

    uint32_t                           count; ///< count
    ifcs_devport_an_bp_tech_ability_t *arr;   ///< List of devport Auto-Neg base page tech ability
} ifcs_devport_an_bp_tech_ability_list_t;

typedef uint32_t ifcs_isg_t;

/**
 * @brief structure of all extended field values
 */
typedef struct ifcs_extended_field_value_s {

    ifcs_mac_t     mac_da;                            ///< destination mac address
    ifcs_mac_t     mac_sa;                            ///< source mac address
    ifcs_uint16_t  svid;                              ///< service tag
    ifcs_uint16_t  cvid;                              ///< customer tag
    ifcs_uint16_t  ether_type;                        ///< ether type of the packet
    ifcs_ip_addr_t ipv4_destination_ip;               ///< IPV4 destination address
    ifcs_ip_addr_t ipv4_source_ip;                    ///< IPV4 source address
    ifcs_uint16_t  ipv4_protocol;                     ///< IPV4 protocol number
    ifcs_ip_addr_t ipv6_destination_ip;               ///< IPV6 destination address
    ifcs_ip_addr_t ipv6_source_ip;                    ///< IPV6 source address
    ifcs_uint8_t   ipv6_nextheader;                   ///< IPV6 next header
    ifcs_uint32_t  ipv6_flow_label;                   ///< IPV6 flow label
    ifcs_uint32_t  tcp_or_udp_source_port;            ///< TCP/UDP Source Port
    ifcs_uint32_t  tcp_or_udp_dest_port;              ///< TCP/UDP Destination Port
    ifcs_uint32_t  gre_key;                           ///< GRE Key
    ifcs_uint16_t  gre_protocol;                      ///< GRE Protocol
    ifcs_handle_t  source_sysport;                    ///< Source sysport handle
    ifcs_uint8_t   _dirty_mac_da : 1;                 ///< indicates if user has set mac_da
    ifcs_uint8_t   _dirty_mac_sa : 1;                 ///< indicates if user has set mac_sa
    ifcs_uint8_t   _dirty_svid : 1;                   ///< indicates if user has set svid
    ifcs_uint8_t   _dirty_cvid : 1;                   ///< indicates if user has set cvid
    ifcs_uint8_t   _dirty_ether_type : 1;             ///< indicates if user has set ether_type
    ifcs_uint8_t   _dirty_ipv4_destination_ip : 1;    ///< indicates if user has set ipv4_destination_ip
    ifcs_uint8_t   _dirty_ipv4_source_ip : 1;         ///< indicates if user has set ipv4_source_ip
    ifcs_uint8_t   _dirty_ipv4_protocol : 1;          ///< indicates if user has set ipv4_protocol
    ifcs_uint8_t   _dirty_ipv6_destination_ip : 1;    ///< indicates if user has set ipv6_destination_ip
    ifcs_uint8_t   _dirty_ipv6_source_ip : 1;         ///< indicates if user has set ipv6_source_ip
    ifcs_uint8_t   _dirty_ipv6_nextheader : 1;        ///< indicates if user has set ipv6_nextheader
    ifcs_uint8_t   _dirty_ipv6_flow_label : 1;        ///< indicates if user has set ipv6_flow_label
    ifcs_uint8_t   _dirty_tcp_or_udp_source_port : 1; ///< indicates if user has set tcp_or_udp_source_port
    ifcs_uint8_t   _dirty_tcp_or_udp_dest_port : 1;   ///< indicates if user has set tcp_or_udp_dest_port
    ifcs_uint8_t   _dirty_gre_key : 1;                ///< indicates if user has set gre_key
    ifcs_uint8_t   _dirty_gre_protocol : 1;           ///< indicates if user has set gre_protocol
    ifcs_uint8_t   _dirty_source_sysport : 1;         ///< indicates if user has set source_sysport
} ifcs_extended_field_value_t;

/**
 * @brief Initialize the extended_field_value structure
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_init(ifcs_extended_field_value_t *extended_field_value_p);
/**
 * @brief Set the extended_field_value structure with mac_da
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     mac_da_p                 - mac_da
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_mac_da_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_mac_t *mac_da_p);

/**
 * @brief Get the extended_field_value structure with mac_da
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     mac_da_p                 - mac_da
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_mac_da_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_mac_t *mac_da_p);

/**
 * @brief Set the extended_field_value structure with mac_sa
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     mac_sa_p                 - mac_sa
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_mac_sa_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_mac_t *mac_sa_p);

/**
 * @brief Get the extended_field_value structure with mac_sa
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     mac_sa_p                 - mac_sa
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_mac_sa_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_mac_t *mac_sa_p);

/**
 * @brief Set the extended_field_value structure with svid
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     svid                     - svid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_svid_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint16_t svid);

/**
 * @brief Get the extended_field_value structure with svid
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     svid_p                   - svid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_svid_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint16_t *svid_p);

/**
 * @brief Set the extended_field_value structure with cvid
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     cvid                     - cvid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_cvid_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint16_t cvid);

/**
 * @brief Get the extended_field_value structure with cvid
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     cvid_p                   - cvid
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_cvid_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint16_t *cvid_p);

/**
 * @brief Set the extended_field_value structure with ether_type
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ether_type               - ether_type
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ether_type_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint16_t ether_type);

/**
 * @brief Get the extended_field_value structure with ether_type
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ether_type_p             - ether_type
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ether_type_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint16_t *ether_type_p);

/**
 * @brief Set the extended_field_value structure with ipv4_destination_ip
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ipv4_destination_ip_p    - ipv4_destination_ip
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ipv4_destination_ip_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_ip_addr_t *ipv4_destination_ip_p);

/**
 * @brief Get the extended_field_value structure with ipv4_destination_ip
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ipv4_destination_ip_p    - ipv4_destination_ip
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ipv4_destination_ip_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_ip_addr_t *ipv4_destination_ip_p);

/**
 * @brief Set the extended_field_value structure with ipv4_source_ip
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ipv4_source_ip_p         - ipv4_source_ip
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ipv4_source_ip_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_ip_addr_t *ipv4_source_ip_p);

/**
 * @brief Get the extended_field_value structure with ipv4_source_ip
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ipv4_source_ip_p         - ipv4_source_ip
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ipv4_source_ip_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_ip_addr_t *ipv4_source_ip_p);

/**
 * @brief Set the extended_field_value structure with ipv4_protocol
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ipv4_protocol            - ipv4_protocol
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ipv4_protocol_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint16_t ipv4_protocol);

/**
 * @brief Get the extended_field_value structure with ipv4_protocol
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ipv4_protocol_p          - ipv4_protocol
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ipv4_protocol_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint16_t *ipv4_protocol_p);

/**
 * @brief Set the extended_field_value structure with ipv6_destination_ip
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ipv6_destination_ip_p    - ipv6_destination_ip
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ipv6_destination_ip_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_ip_addr_t *ipv6_destination_ip_p);

/**
 * @brief Get the extended_field_value structure with ipv6_destination_ip
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ipv6_destination_ip_p    - ipv6_destination_ip
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ipv6_destination_ip_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_ip_addr_t *ipv6_destination_ip_p);

/**
 * @brief Set the extended_field_value structure with ipv6_source_ip
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ipv6_source_ip_p         - ipv6_source_ip
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ipv6_source_ip_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_ip_addr_t *ipv6_source_ip_p);

/**
 * @brief Get the extended_field_value structure with ipv6_source_ip
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ipv6_source_ip_p         - ipv6_source_ip
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ipv6_source_ip_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_ip_addr_t *ipv6_source_ip_p);

/**
 * @brief Set the extended_field_value structure with ipv6_nextheader
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ipv6_nextheader          - ipv6_nextheader
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ipv6_nextheader_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint8_t ipv6_nextheader);

/**
 * @brief Get the extended_field_value structure with ipv6_nextheader
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ipv6_nextheader_p        - ipv6_nextheader
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ipv6_nextheader_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint8_t *ipv6_nextheader_p);

/**
 * @brief Set the extended_field_value structure with ipv6_flow_label
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ipv6_flow_label          - ipv6_flow_label
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ipv6_flow_label_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint32_t ipv6_flow_label);

/**
 * @brief Get the extended_field_value structure with ipv6_flow_label
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     ipv6_flow_label_p        - ipv6_flow_label
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_ipv6_flow_label_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint32_t *ipv6_flow_label_p);

/**
 * @brief Set the extended_field_value structure with tcp_or_udp_source_port
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     tcp_or_udp_source_port   - tcp_or_udp_source_port
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_tcp_or_udp_source_port_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint32_t tcp_or_udp_source_port);

/**
 * @brief Get the extended_field_value structure with tcp_or_udp_source_port
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     tcp_or_udp_source_port_p - tcp_or_udp_source_port
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_tcp_or_udp_source_port_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint32_t *tcp_or_udp_source_port_p);

/**
 * @brief Set the extended_field_value structure with tcp_or_udp_dest_port
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     tcp_or_udp_dest_port     - tcp_or_udp_dest_port
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_tcp_or_udp_dest_port_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint32_t tcp_or_udp_dest_port);

/**
 * @brief Get the extended_field_value structure with tcp_or_udp_dest_port
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     tcp_or_udp_dest_port_p   - tcp_or_udp_dest_port
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_tcp_or_udp_dest_port_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint32_t *tcp_or_udp_dest_port_p);

/**
 * @brief Set the extended_field_value structure with gre_key
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     gre_key                  - gre_key
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_gre_key_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint32_t gre_key);

/**
 * @brief Get the extended_field_value structure with gre_key
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     gre_key_p                - gre_key
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_gre_key_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint32_t *gre_key_p);

/**
 * @brief Set the extended_field_value structure with gre_protocol
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     gre_protocol             - gre_protocol
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_gre_protocol_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint16_t gre_protocol);

/**
 * @brief Get the extended_field_value structure with gre_protocol
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     gre_protocol_p           - gre_protocol
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_gre_protocol_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_uint16_t *gre_protocol_p);

/**
 * @brief Set the extended_field_value structure with source_sysport
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     source_sysport           - source_sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_source_sysport_set(ifcs_extended_field_value_t *extended_field_value_p, ifcs_handle_t source_sysport);

/**
 * @brief Get the extended_field_value structure with source_sysport
 *
 * @param [in,out] extended_field_value_p   - extended_field_value
 * @param [in]     source_sysport_p         - source_sysport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_extended_field_value_t_source_sysport_get(ifcs_extended_field_value_t *extended_field_value_p, ifcs_handle_t *source_sysport_p);

/**
 * @brief List of MAC address
 */
typedef struct ifcs_mac_list_s {

    uint32_t    count; ///< count
    ifcs_mac_t *arr;   ///< List of MAC address
} ifcs_mac_list_t;

/**
 * @brief Datastructure for 80b PTP-time and 48b device-time
 */
typedef struct ifcs_ptp_time_s {

    ifcs_uint64_t ptptime_seconds;                     ///< 48 bit seconds field of synchronized PTP time
    ifcs_uint32_t ptptime_nanoseconds;                 ///< 32 bit nano-seconds field of synchronized PTP time
    ifcs_uint64_t device_timer_nanoseconds;            ///< 48 bit nano-seconds device timer
    ifcs_uint8_t  _dirty_ptptime_seconds : 1;          ///< indicates if user has set ptptime_seconds
    ifcs_uint8_t  _dirty_ptptime_nanoseconds : 1;      ///< indicates if user has set ptptime_nanoseconds
    ifcs_uint8_t  _dirty_device_timer_nanoseconds : 1; ///< indicates if user has set device_timer_nanoseconds
} ifcs_ptp_time_t;

/**
 * @brief Initialize the ptp_time structure
 *
 * @param [in,out] ptp_time_p                 - ptp_time
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_time_t_init(ifcs_ptp_time_t *ptp_time_p);
/**
 * @brief Set the ptp_time structure with ptptime_seconds
 *
 * @param [in,out] ptp_time_p                 - ptp_time
 * @param [in]     ptptime_seconds            - ptptime_seconds
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_time_t_ptptime_seconds_set(ifcs_ptp_time_t *ptp_time_p, ifcs_uint64_t ptptime_seconds);

/**
 * @brief Get the ptp_time structure with ptptime_seconds
 *
 * @param [in,out] ptp_time_p                 - ptp_time
 * @param [in]     ptptime_seconds_p          - ptptime_seconds
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_time_t_ptptime_seconds_get(ifcs_ptp_time_t *ptp_time_p, ifcs_uint64_t *ptptime_seconds_p);

/**
 * @brief Set the ptp_time structure with ptptime_nanoseconds
 *
 * @param [in,out] ptp_time_p                 - ptp_time
 * @param [in]     ptptime_nanoseconds        - ptptime_nanoseconds
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_time_t_ptptime_nanoseconds_set(ifcs_ptp_time_t *ptp_time_p, ifcs_uint32_t ptptime_nanoseconds);

/**
 * @brief Get the ptp_time structure with ptptime_nanoseconds
 *
 * @param [in,out] ptp_time_p                 - ptp_time
 * @param [in]     ptptime_nanoseconds_p      - ptptime_nanoseconds
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_time_t_ptptime_nanoseconds_get(ifcs_ptp_time_t *ptp_time_p, ifcs_uint32_t *ptptime_nanoseconds_p);

/**
 * @brief Set the ptp_time structure with device_timer_nanoseconds
 *
 * @param [in,out] ptp_time_p                 - ptp_time
 * @param [in]     device_timer_nanoseconds   - device_timer_nanoseconds
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_time_t_device_timer_nanoseconds_set(ifcs_ptp_time_t *ptp_time_p, ifcs_uint64_t device_timer_nanoseconds);

/**
 * @brief Get the ptp_time structure with device_timer_nanoseconds
 *
 * @param [in,out] ptp_time_p                 - ptp_time
 * @param [in]     device_timer_nanoseconds_p - device_timer_nanoseconds
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_time_t_device_timer_nanoseconds_get(ifcs_ptp_time_t *ptp_time_p, ifcs_uint64_t *device_timer_nanoseconds_p);

/**
 * @brief Datastructure for 80b PTP time offset
 */
typedef struct ifcs_ptp_timeoffset_s {

    ifcs_uint64_t seconds;                ///< 48 bit seconds field of PTP time offset
    ifcs_uint32_t nanoseconds;            ///< 32 bit nano-seconds field of PTP time offset
    ifcs_uint8_t  _dirty_seconds : 1;     ///< indicates if user has set seconds
    ifcs_uint8_t  _dirty_nanoseconds : 1; ///< indicates if user has set nanoseconds
} ifcs_ptp_timeoffset_t;

/**
 * @brief Initialize the ptp_timeoffset structure
 *
 * @param [in,out] ptp_timeoffset_p - ptp_timeoffset
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_timeoffset_t_init(ifcs_ptp_timeoffset_t *ptp_timeoffset_p);
/**
 * @brief Set the ptp_timeoffset structure with seconds
 *
 * @param [in,out] ptp_timeoffset_p - ptp_timeoffset
 * @param [in]     seconds          - seconds
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_timeoffset_t_seconds_set(ifcs_ptp_timeoffset_t *ptp_timeoffset_p, ifcs_uint64_t seconds);

/**
 * @brief Get the ptp_timeoffset structure with seconds
 *
 * @param [in,out] ptp_timeoffset_p - ptp_timeoffset
 * @param [in]     seconds_p        - seconds
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_timeoffset_t_seconds_get(ifcs_ptp_timeoffset_t *ptp_timeoffset_p, ifcs_uint64_t *seconds_p);

/**
 * @brief Set the ptp_timeoffset structure with nanoseconds
 *
 * @param [in,out] ptp_timeoffset_p - ptp_timeoffset
 * @param [in]     nanoseconds      - nanoseconds
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_timeoffset_t_nanoseconds_set(ifcs_ptp_timeoffset_t *ptp_timeoffset_p, ifcs_uint32_t nanoseconds);

/**
 * @brief Get the ptp_timeoffset structure with nanoseconds
 *
 * @param [in,out] ptp_timeoffset_p - ptp_timeoffset
 * @param [in]     nanoseconds_p    - nanoseconds
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_timeoffset_t_nanoseconds_get(ifcs_ptp_timeoffset_t *ptp_timeoffset_p, ifcs_uint32_t *nanoseconds_p);

/**
 * @brief Datastructure for PTP syntonization
 */
typedef struct ifcs_ptp_syntonize_s {

    ifcs_int32_t parts_per_trillion;            ///< Target frequency delta in parts per trillion
    ifcs_uint8_t _dirty_parts_per_trillion : 1; ///< indicates if user has set parts_per_trillion
} ifcs_ptp_syntonize_t;

/**
 * @brief Initialize the ptp_syntonize structure
 *
 * @param [in,out] ptp_syntonize_p      - ptp_syntonize
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_syntonize_t_init(ifcs_ptp_syntonize_t *ptp_syntonize_p);
/**
 * @brief Set the ptp_syntonize structure with parts_per_trillion
 *
 * @param [in,out] ptp_syntonize_p      - ptp_syntonize
 * @param [in]     parts_per_trillion   - parts_per_trillion
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_syntonize_t_parts_per_trillion_set(ifcs_ptp_syntonize_t *ptp_syntonize_p, ifcs_int32_t parts_per_trillion);

/**
 * @brief Get the ptp_syntonize structure with parts_per_trillion
 *
 * @param [in,out] ptp_syntonize_p      - ptp_syntonize
 * @param [in]     parts_per_trillion_p - parts_per_trillion
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_syntonize_t_parts_per_trillion_get(ifcs_ptp_syntonize_t *ptp_syntonize_p, ifcs_int32_t *parts_per_trillion_p);

/**
 * @brief Enable/disable PTP on this devport for PTP instance
 */
typedef struct ifcs_ptp_policy_s {

    ifcs_handle_t ptp_instance_handle;            ///< Handle for PTP instance
    ifcs_bool_t   ptp_enable;                     ///< Enable/disable PTP on this devport
    ifcs_uint8_t  _dirty_ptp_instance_handle : 1; ///< indicates if user has set ptp_instance_handle
    ifcs_uint8_t  _dirty_ptp_enable : 1;          ///< indicates if user has set ptp_enable
} ifcs_ptp_policy_t;

/**
 * @brief Initialize the ptp_policy structure
 *
 * @param [in,out] ptp_policy_p          - ptp_policy
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_policy_t_init(ifcs_ptp_policy_t *ptp_policy_p);
/**
 * @brief Set the ptp_policy structure with ptp_instance_handle
 *
 * @param [in,out] ptp_policy_p          - ptp_policy
 * @param [in]     ptp_instance_handle   - ptp_instance_handle
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_policy_t_ptp_instance_handle_set(ifcs_ptp_policy_t *ptp_policy_p, ifcs_handle_t ptp_instance_handle);

/**
 * @brief Get the ptp_policy structure with ptp_instance_handle
 *
 * @param [in,out] ptp_policy_p          - ptp_policy
 * @param [in]     ptp_instance_handle_p - ptp_instance_handle
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_policy_t_ptp_instance_handle_get(ifcs_ptp_policy_t *ptp_policy_p, ifcs_handle_t *ptp_instance_handle_p);

/**
 * @brief Set the ptp_policy structure with ptp_enable
 *
 * @param [in,out] ptp_policy_p          - ptp_policy
 * @param [in]     ptp_enable            - ptp_enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_policy_t_ptp_enable_set(ifcs_ptp_policy_t *ptp_policy_p, ifcs_bool_t ptp_enable);

/**
 * @brief Get the ptp_policy structure with ptp_enable
 *
 * @param [in,out] ptp_policy_p          - ptp_policy
 * @param [in]     ptp_enable_p          - ptp_enable
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_ptp_policy_t_ptp_enable_get(ifcs_ptp_policy_t *ptp_policy_p, ifcs_bool_t *ptp_enable_p);

/**
 * @brief List of devport speeds
 */
typedef struct ifcs_devport_speed_list_s {

    uint32_t              count; ///< count
    ifcs_devport_speed_t *arr;   ///< List of devport speeds
} ifcs_devport_speed_list_t;

/**
 * @brief Attribute for IFCS API calls
 */
typedef union ifcs_attr_value_u {

    ifcs_uint64_t                          u64;                             ///< unsigned 64bit integer
    ifcs_uint32_t                          u32;                             ///< unsigned 32bit integer
    ifcs_int32_t                           int32;                           ///< signed 32bit integer
    ifcs_uint16_t                          u16;                             ///< unsigned 16bit integer
    ifcs_uint8_t                           u8;                              ///< unsigned 8bit integer
    ifcs_flt_t                             flt;                             ///< floating point
    ifcs_u8_list_t                         u8_list;                         ///< list of uint8
    ifcs_string_t                          string;                          ///< list of uint8
    ifcs_i8_list_t                         i8_list;                         ///< list of int8
    ifcs_i32_list_t                        i32_list;                        ///< list of int32
    ifcs_u32_list_t                        u32_list;                        ///< list of uint32
    ifcs_u64_list_t                        u64_list;                        ///< list of uint64
    ifcs_flt_list_t                        flt_list;                        ///< list of flt
    ifcs_devport_t                         devport;                         ///< Device Port
    ifcs_ib_t                              ib;                              ///< Inno Block(IB) id
    ifcs_ib_list_t                         ib_list;                         ///< Inno Block(IB) id list
    ifcs_partition_id_t                    partition_id;                    ///< Partition id
    ifcs_cpu_queue_t                       cpu_queue;                       ///< CPU queue id
    ifcs_queue_id_t                        queue_id;                        ///< Class of Service Queue
    ifcs_cpu_queue_list_t                  cpu_queue_list;                  ///< List of CPU queues
    ifcs_tc_t                              tc;                              ///< Traffic Class ID
    ifcs_bool_t                            data;                            ///< IFCS bool type
    ifcs_ip_address_t                      ip_addr;                         ///< ip_address
    ifcs_ip_prefix_t                       ip_prefix;                       ///< IP address with prefix
    ifcs_mac_t                             mac;                             ///< IFCS mac address
    ifcs_handle_t                          handle;                          ///< handle
    ifcs_handle_list_t                     handle_list;                     ///< List of handles
    ifcs_qos_map_list_t                    qos_map_list;                    ///< Dynamic list of QOS map
    ifcs_qos_map_info_t                    qos_map_info;                    ///< QOS map information
    ifcs_ctc_policy_t                      ctc_policy;                      ///< Copy to CPU policy for a given API object
    ifcs_fwd_policy_t                      fwd_policy;                      ///< Forward policy for a given API object
    ifcs_traffic_monitor_policy_t          traffic_monitor_policy;          ///< Traffic_Monitor policy
    ifcs_bdc_policy_t                      bdc_policy;                      ///< BDC policy
    ifcs_hdc_policy_t                      hdc_policy;                      ///< High delay policy
    ifcs_ipt_policy_t                      ipt_policy;                      ///< IPT policy
    ifcs_flex_stats_attributes_t           flex_stats_attributes;           ///< Attributes required to enable extended statistics
    ifcs_acl_action_value_t                acl_action_value;                ///< ACL Action (yellow and red fields are valid when ACE has a meter attached to it)
    ifcs_flex_stats_pkt_attr_map_list_t    flex_stats_pkt_attr_map_list;    ///< Flex pool packet attribute map list
    ifcs_vlan_tag_action_t                 vlan_tag_action;                 ///< data type to encode VLAN tag action
    ifcs_fpf_match_list_t                  fpf_match_list;                  ///< Match conditions to extract the packet fields
    ifcs_fpf_extraction_cmd_list_t         fpf_extraction_cmd_list;         ///< Commands to extract the fields
    ifcs_devport_an_bp_tech_ability_list_t devport_an_bp_tech_ability_list; ///< List of devport Auto-Neg base page tech ability
    ifcs_extended_field_value_t            extended_field_value;            ///< structure of all extended field values
    ifcs_mac_list_t                        mac_list;                        ///< List of MAC address
    ifcs_ptp_time_t                        ptp_time;                        ///< Datastructure for 80b PTP-time and 48b device-time
    ifcs_ptp_timeoffset_t                  ptp_timeoffset;                  ///< Datastructure for 80b PTP time offset
    ifcs_ptp_policy_t                      ptp_policy;                      ///< Enable/disable PTP on this devport for PTP instance
    ifcs_devport_speed_list_t              devport_speed_list;              ///< List of devport speeds
} ifcs_attr_value_t;

/**
 * @brief Bitmap to find out which attribute value type is set
 */
typedef struct ifcs_attr_value_bitmap_s {

    ifcs_uint64_t u64 : 1;                             ///< unsigned 64bit integer
    ifcs_uint64_t u32 : 1;                             ///< unsigned 32bit integer
    ifcs_uint64_t int32 : 1;                           ///< signed 32bit integer
    ifcs_uint64_t u16 : 1;                             ///< unsigned 16bit integer
    ifcs_uint64_t u8 : 1;                              ///< unsigned 8bit integer
    ifcs_uint64_t flt : 1;                             ///< floating point
    ifcs_uint64_t u8_list : 1;                         ///< list of uint8
    ifcs_uint64_t string : 1;                          ///< list of uint8
    ifcs_uint64_t i8_list : 1;                         ///< list of int8
    ifcs_uint64_t i32_list : 1;                        ///< list of int32
    ifcs_uint64_t u32_list : 1;                        ///< list of uint32
    ifcs_uint64_t u64_list : 1;                        ///< list of uint64
    ifcs_uint64_t flt_list : 1;                        ///< list of flt
    ifcs_uint64_t devport : 1;                         ///< Device Port
    ifcs_uint64_t ib : 1;                              ///< Inno Block(IB) id
    ifcs_uint64_t ib_list : 1;                         ///< Inno Block(IB) id list
    ifcs_uint64_t partition_id : 1;                    ///< Partition id
    ifcs_uint64_t cpu_queue : 1;                       ///< CPU queue id
    ifcs_uint64_t queue_id : 1;                        ///< Class of Service Queue
    ifcs_uint64_t cpu_queue_list : 1;                  ///< List of CPU queues
    ifcs_uint64_t tc : 1;                              ///< Traffic Class ID
    ifcs_uint64_t data : 1;                            ///< IFCS bool type
    ifcs_uint64_t ip_addr : 1;                         ///< ip_address
    ifcs_uint64_t ip_prefix : 1;                       ///< IP address with prefix
    ifcs_uint64_t mac : 1;                             ///< IFCS mac address
    ifcs_uint64_t handle : 1;                          ///< handle
    ifcs_uint64_t handle_list : 1;                     ///< List of handles
    ifcs_uint64_t qos_map_list : 1;                    ///< Dynamic list of QOS map
    ifcs_uint64_t qos_map_info : 1;                    ///< QOS map information
    ifcs_uint64_t ctc_policy : 1;                      ///< Copy to CPU policy for a given API object
    ifcs_uint64_t fwd_policy : 1;                      ///< Forward policy for a given API object
    ifcs_uint64_t traffic_monitor_policy : 1;          ///< Traffic_Monitor policy
    ifcs_uint64_t bdc_policy : 1;                      ///< BDC policy
    ifcs_uint64_t hdc_policy : 1;                      ///< High delay policy
    ifcs_uint64_t ipt_policy : 1;                      ///< IPT policy
    ifcs_uint64_t flex_stats_attributes : 1;           ///< Attributes required to enable extended statistics
    ifcs_uint64_t acl_action_value : 1;                ///< ACL Action (yellow and red fields are valid when ACE has a meter attached to it)
    ifcs_uint64_t flex_stats_pkt_attr_map_list : 1;    ///< Flex pool packet attribute map list
    ifcs_uint64_t vlan_tag_action : 1;                 ///< data type to encode VLAN tag action
    ifcs_uint64_t fpf_match_list : 1;                  ///< Match conditions to extract the packet fields
    ifcs_uint64_t fpf_extraction_cmd_list : 1;         ///< Commands to extract the fields
    ifcs_uint64_t devport_an_bp_tech_ability_list : 1; ///< List of devport Auto-Neg base page tech ability
    ifcs_uint64_t extended_field_value : 1;            ///< structure of all extended field values
    ifcs_uint64_t mac_list : 1;                        ///< List of MAC address
    ifcs_uint64_t ptp_time : 1;                        ///< Datastructure for 80b PTP-time and 48b device-time
    ifcs_uint64_t ptp_timeoffset : 1;                  ///< Datastructure for 80b PTP time offset
    ifcs_uint64_t ptp_policy : 1;                      ///< Enable/disable PTP on this devport for PTP instance
    ifcs_uint64_t devport_speed_list : 1;              ///< List of devport speeds
    ifcs_uint64_t dummy : 16;                          ///< Padding unused bits
} ifcs_attr_value_bitmap_t;

/**
 * @brief Attribute for IFCS API calls
 */
typedef struct ifcs_attr_s {

    ifcs_attr_id_t           id;     ///< Attribute type
    ifcs_attr_value_t        value;  ///< Attribute value
    ifcs_attr_value_bitmap_t bitmap; ///< Bitmap to check which data type is set
} ifcs_attr_t;

/**
 * @brief Initialize the attr structure
 *
 * @param [in,out] attr_p - attr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_init(ifcs_attr_t *attr_p);

typedef ifcs_attr_t *ifcs_attr_p_t;

/**
 * @brief Set the id in ifcs_attr_t structure
 *
 * @param [in,out] attr_p - IFCS attribute pointer
 * @param [in]     id     - IFCS attribute id
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_id_set(ifcs_attr_t *attr_p, uint32_t id);

/**
 * @brief Get the id from ifcs_attr_t structure
 *
 * @param [in]     attr_p - IFCS attribute pointer
 * @param [in,out] id     - IFCS attribute id
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_id_get(ifcs_attr_t *attr_p, uint32_t *id);

/**
 * @brief Set the u64 union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p - IFCS attribute pointer
 * @param [in]     u64    - u64
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_u64_set(ifcs_attr_t *attr_p, ifcs_uint64_t u64);

/**
 * @brief Get the u64 union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p - IFCS attribute pointer
 * @param [in,out] u64_p  - return u64 value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_u64_get(ifcs_attr_t *attr_p, ifcs_uint64_t *u64_p);

/**
 * @brief Set the u32 union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p - IFCS attribute pointer
 * @param [in]     u32    - u32
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_u32_set(ifcs_attr_t *attr_p, ifcs_uint32_t u32);

/**
 * @brief Get the u32 union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p - IFCS attribute pointer
 * @param [in,out] u32_p  - return u32 value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_u32_get(ifcs_attr_t *attr_p, ifcs_uint32_t *u32_p);

/**
 * @brief Set the int32 union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p  - IFCS attribute pointer
 * @param [in]     int32   - int32
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_int32_set(ifcs_attr_t *attr_p, ifcs_int32_t int32);

/**
 * @brief Get the int32 union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p  - IFCS attribute pointer
 * @param [in,out] int32_p - return int32 value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_int32_get(ifcs_attr_t *attr_p, ifcs_int32_t *int32_p);

/**
 * @brief Set the u16 union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p - IFCS attribute pointer
 * @param [in]     u16    - u16
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_u16_set(ifcs_attr_t *attr_p, ifcs_uint16_t u16);

/**
 * @brief Get the u16 union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p - IFCS attribute pointer
 * @param [in,out] u16_p  - return u16 value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_u16_get(ifcs_attr_t *attr_p, ifcs_uint16_t *u16_p);

/**
 * @brief Set the u8 union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p - IFCS attribute pointer
 * @param [in]     u8     - u8
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_u8_set(ifcs_attr_t *attr_p, ifcs_uint8_t u8);

/**
 * @brief Get the u8 union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p - IFCS attribute pointer
 * @param [in,out] u8_p   - return u8 value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_u8_get(ifcs_attr_t *attr_p, ifcs_uint8_t *u8_p);

/**
 * @brief Set the flt union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p - IFCS attribute pointer
 * @param [in]     flt    - flt
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_flt_set(ifcs_attr_t *attr_p, ifcs_flt_t flt);

/**
 * @brief Get the flt union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p - IFCS attribute pointer
 * @param [in,out] flt_p  - return flt value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_flt_get(ifcs_attr_t *attr_p, ifcs_flt_t *flt_p);

/**
 * @brief Set the u8_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p    - IFCS attribute pointer
 * @param [in]     u8_list_p - u8_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_u8_list_set(ifcs_attr_t *attr_p, ifcs_u8_list_t *u8_list_p);

/**
 * @brief Get the u8_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p    - IFCS attribute pointer
 * @param [in,out] u8_list_p - return u8_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_u8_list_get(ifcs_attr_t *attr_p, ifcs_u8_list_t *u8_list_p);

/**
 * @brief Set the string union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p   - IFCS attribute pointer
 * @param [in]     string_p - string
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_string_set(ifcs_attr_t *attr_p, ifcs_string_t *string_p);

/**
 * @brief Get the string union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p   - IFCS attribute pointer
 * @param [in,out] string_p - return string value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_string_get(ifcs_attr_t *attr_p, ifcs_string_t *string_p);

/**
 * @brief Set the i8_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p    - IFCS attribute pointer
 * @param [in]     i8_list_p - i8_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_i8_list_set(ifcs_attr_t *attr_p, ifcs_i8_list_t *i8_list_p);

/**
 * @brief Get the i8_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p    - IFCS attribute pointer
 * @param [in,out] i8_list_p - return i8_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_i8_list_get(ifcs_attr_t *attr_p, ifcs_i8_list_t *i8_list_p);

/**
 * @brief Set the i32_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p     - IFCS attribute pointer
 * @param [in]     i32_list_p - i32_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_i32_list_set(ifcs_attr_t *attr_p, ifcs_i32_list_t *i32_list_p);

/**
 * @brief Get the i32_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p     - IFCS attribute pointer
 * @param [in,out] i32_list_p - return i32_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_i32_list_get(ifcs_attr_t *attr_p, ifcs_i32_list_t *i32_list_p);

/**
 * @brief Set the u32_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p     - IFCS attribute pointer
 * @param [in]     u32_list_p - u32_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_u32_list_set(ifcs_attr_t *attr_p, ifcs_u32_list_t *u32_list_p);

/**
 * @brief Get the u32_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p     - IFCS attribute pointer
 * @param [in,out] u32_list_p - return u32_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_u32_list_get(ifcs_attr_t *attr_p, ifcs_u32_list_t *u32_list_p);

/**
 * @brief Set the u64_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p     - IFCS attribute pointer
 * @param [in]     u64_list_p - u64_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_u64_list_set(ifcs_attr_t *attr_p, ifcs_u64_list_t *u64_list_p);

/**
 * @brief Get the u64_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p     - IFCS attribute pointer
 * @param [in,out] u64_list_p - return u64_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_u64_list_get(ifcs_attr_t *attr_p, ifcs_u64_list_t *u64_list_p);

/**
 * @brief Set the flt_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p     - IFCS attribute pointer
 * @param [in]     flt_list_p - flt_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_flt_list_set(ifcs_attr_t *attr_p, ifcs_flt_list_t *flt_list_p);

/**
 * @brief Get the flt_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p     - IFCS attribute pointer
 * @param [in,out] flt_list_p - return flt_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_flt_list_get(ifcs_attr_t *attr_p, ifcs_flt_list_t *flt_list_p);

/**
 * @brief Set the devport union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p    - IFCS attribute pointer
 * @param [in]     devport   - devport
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_devport_set(ifcs_attr_t *attr_p, ifcs_devport_t devport);

/**
 * @brief Get the devport union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p    - IFCS attribute pointer
 * @param [in,out] devport_p - return devport value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_devport_get(ifcs_attr_t *attr_p, ifcs_devport_t *devport_p);

/**
 * @brief Set the ib union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p - IFCS attribute pointer
 * @param [in]     ib     - ib
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ib_set(ifcs_attr_t *attr_p, ifcs_ib_t ib);

/**
 * @brief Get the ib union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p - IFCS attribute pointer
 * @param [in,out] ib_p   - return ib value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ib_get(ifcs_attr_t *attr_p, ifcs_ib_t *ib_p);

/**
 * @brief Set the ib_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p    - IFCS attribute pointer
 * @param [in]     ib_list_p - ib_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ib_list_set(ifcs_attr_t *attr_p, ifcs_ib_list_t *ib_list_p);

/**
 * @brief Get the ib_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p    - IFCS attribute pointer
 * @param [in,out] ib_list_p - return ib_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ib_list_get(ifcs_attr_t *attr_p, ifcs_ib_list_t *ib_list_p);

/**
 * @brief Set the partition_id union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p         - IFCS attribute pointer
 * @param [in]     partition_id   - partition_id
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_partition_id_set(ifcs_attr_t *attr_p, ifcs_partition_id_t partition_id);

/**
 * @brief Get the partition_id union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p         - IFCS attribute pointer
 * @param [in,out] partition_id_p - return partition_id value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_partition_id_get(ifcs_attr_t *attr_p, ifcs_partition_id_t *partition_id_p);

/**
 * @brief Set the cpu_queue union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p      - IFCS attribute pointer
 * @param [in]     cpu_queue   - cpu_queue
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_cpu_queue_set(ifcs_attr_t *attr_p, ifcs_cpu_queue_t cpu_queue);

/**
 * @brief Get the cpu_queue union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p      - IFCS attribute pointer
 * @param [in,out] cpu_queue_p - return cpu_queue value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_cpu_queue_get(ifcs_attr_t *attr_p, ifcs_cpu_queue_t *cpu_queue_p);

/**
 * @brief Set the queue_id union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p     - IFCS attribute pointer
 * @param [in]     queue_id   - queue_id
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_queue_id_set(ifcs_attr_t *attr_p, ifcs_queue_id_t queue_id);

/**
 * @brief Get the queue_id union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p     - IFCS attribute pointer
 * @param [in,out] queue_id_p - return queue_id value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_queue_id_get(ifcs_attr_t *attr_p, ifcs_queue_id_t *queue_id_p);

/**
 * @brief Set the cpu_queue_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p           - IFCS attribute pointer
 * @param [in]     cpu_queue_list_p - cpu_queue_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_cpu_queue_list_set(ifcs_attr_t *attr_p, ifcs_cpu_queue_list_t *cpu_queue_list_p);

/**
 * @brief Get the cpu_queue_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p           - IFCS attribute pointer
 * @param [in,out] cpu_queue_list_p - return cpu_queue_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_cpu_queue_list_get(ifcs_attr_t *attr_p, ifcs_cpu_queue_list_t *cpu_queue_list_p);

/**
 * @brief Set the tc union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p - IFCS attribute pointer
 * @param [in]     tc     - tc
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_tc_set(ifcs_attr_t *attr_p, ifcs_tc_t tc);

/**
 * @brief Get the tc union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p - IFCS attribute pointer
 * @param [in,out] tc_p   - return tc value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_tc_get(ifcs_attr_t *attr_p, ifcs_tc_t *tc_p);

/**
 * @brief Set the data union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p - IFCS attribute pointer
 * @param [in]     data   - data
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_data_set(ifcs_attr_t *attr_p, ifcs_bool_t data);

/**
 * @brief Get the data union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p - IFCS attribute pointer
 * @param [in,out] data_p - return data value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_data_get(ifcs_attr_t *attr_p, ifcs_bool_t *data_p);

/**
 * @brief Set the ip_addr union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p    - IFCS attribute pointer
 * @param [in]     ip_addr_p - ip_addr
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ip_addr_set(ifcs_attr_t *attr_p, ifcs_ip_address_t *ip_addr_p);

/**
 * @brief Get the ip_addr union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p    - IFCS attribute pointer
 * @param [in,out] ip_addr_p - return ip_addr value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ip_addr_get(ifcs_attr_t *attr_p, ifcs_ip_address_t *ip_addr_p);

/**
 * @brief Set the ip_prefix union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p      - IFCS attribute pointer
 * @param [in]     ip_prefix_p - ip_prefix
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ip_prefix_set(ifcs_attr_t *attr_p, ifcs_ip_prefix_t *ip_prefix_p);

/**
 * @brief Get the ip_prefix union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p      - IFCS attribute pointer
 * @param [in,out] ip_prefix_p - return ip_prefix value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ip_prefix_get(ifcs_attr_t *attr_p, ifcs_ip_prefix_t *ip_prefix_p);

/**
 * @brief Set the mac union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p - IFCS attribute pointer
 * @param [in]     mac_p  - mac
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_mac_set(ifcs_attr_t *attr_p, ifcs_mac_t *mac_p);

/**
 * @brief Get the mac union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p - IFCS attribute pointer
 * @param [in,out] mac_p  - return mac value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_mac_get(ifcs_attr_t *attr_p, ifcs_mac_t *mac_p);

/**
 * @brief Set the handle union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p   - IFCS attribute pointer
 * @param [in]     handle   - handle
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_handle_set(ifcs_attr_t *attr_p, ifcs_handle_t handle);

/**
 * @brief Get the handle union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p   - IFCS attribute pointer
 * @param [in,out] handle_p - return handle value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_handle_get(ifcs_attr_t *attr_p, ifcs_handle_t *handle_p);

/**
 * @brief Set the handle_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p        - IFCS attribute pointer
 * @param [in]     handle_list_p - handle_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_handle_list_set(ifcs_attr_t *attr_p, ifcs_handle_list_t *handle_list_p);

/**
 * @brief Get the handle_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p        - IFCS attribute pointer
 * @param [in,out] handle_list_p - return handle_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_handle_list_get(ifcs_attr_t *attr_p, ifcs_handle_list_t *handle_list_p);

/**
 * @brief Set the qos_map_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p         - IFCS attribute pointer
 * @param [in]     qos_map_list_p - qos_map_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_qos_map_list_set(ifcs_attr_t *attr_p, ifcs_qos_map_list_t *qos_map_list_p);

/**
 * @brief Get the qos_map_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p         - IFCS attribute pointer
 * @param [in,out] qos_map_list_p - return qos_map_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_qos_map_list_get(ifcs_attr_t *attr_p, ifcs_qos_map_list_t *qos_map_list_p);

/**
 * @brief Set the qos_map_info union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p         - IFCS attribute pointer
 * @param [in]     qos_map_info_p - qos_map_info
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_qos_map_info_set(ifcs_attr_t *attr_p, ifcs_qos_map_info_t *qos_map_info_p);

/**
 * @brief Get the qos_map_info union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p         - IFCS attribute pointer
 * @param [in,out] qos_map_info_p - return qos_map_info value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_qos_map_info_get(ifcs_attr_t *attr_p, ifcs_qos_map_info_t *qos_map_info_p);

/**
 * @brief Set the ctc_policy union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p       - IFCS attribute pointer
 * @param [in]     ctc_policy_p - ctc_policy
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ctc_policy_set(ifcs_attr_t *attr_p, ifcs_ctc_policy_t *ctc_policy_p);

/**
 * @brief Get the ctc_policy union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p       - IFCS attribute pointer
 * @param [in,out] ctc_policy_p - return ctc_policy value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ctc_policy_get(ifcs_attr_t *attr_p, ifcs_ctc_policy_t *ctc_policy_p);

/**
 * @brief Set the fwd_policy union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p       - IFCS attribute pointer
 * @param [in]     fwd_policy_p - fwd_policy
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_fwd_policy_set(ifcs_attr_t *attr_p, ifcs_fwd_policy_t *fwd_policy_p);

/**
 * @brief Get the fwd_policy union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p       - IFCS attribute pointer
 * @param [in,out] fwd_policy_p - return fwd_policy value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_fwd_policy_get(ifcs_attr_t *attr_p, ifcs_fwd_policy_t *fwd_policy_p);

/**
 * @brief Set the traffic_monitor_policy union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p                   - IFCS attribute pointer
 * @param [in]     traffic_monitor_policy_p - traffic_monitor_policy
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_traffic_monitor_policy_set(ifcs_attr_t *attr_p, ifcs_traffic_monitor_policy_t *traffic_monitor_policy_p);

/**
 * @brief Get the traffic_monitor_policy union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p                   - IFCS attribute pointer
 * @param [in,out] traffic_monitor_policy_p - return traffic_monitor_policy value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_traffic_monitor_policy_get(ifcs_attr_t *attr_p, ifcs_traffic_monitor_policy_t *traffic_monitor_policy_p);

/**
 * @brief Set the bdc_policy union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p       - IFCS attribute pointer
 * @param [in]     bdc_policy_p - bdc_policy
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_bdc_policy_set(ifcs_attr_t *attr_p, ifcs_bdc_policy_t *bdc_policy_p);

/**
 * @brief Get the bdc_policy union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p       - IFCS attribute pointer
 * @param [in,out] bdc_policy_p - return bdc_policy value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_bdc_policy_get(ifcs_attr_t *attr_p, ifcs_bdc_policy_t *bdc_policy_p);

/**
 * @brief Set the hdc_policy union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p       - IFCS attribute pointer
 * @param [in]     hdc_policy_p - hdc_policy
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_hdc_policy_set(ifcs_attr_t *attr_p, ifcs_hdc_policy_t *hdc_policy_p);

/**
 * @brief Get the hdc_policy union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p       - IFCS attribute pointer
 * @param [in,out] hdc_policy_p - return hdc_policy value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_hdc_policy_get(ifcs_attr_t *attr_p, ifcs_hdc_policy_t *hdc_policy_p);

/**
 * @brief Set the ipt_policy union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p       - IFCS attribute pointer
 * @param [in]     ipt_policy_p - ipt_policy
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ipt_policy_set(ifcs_attr_t *attr_p, ifcs_ipt_policy_t *ipt_policy_p);

/**
 * @brief Get the ipt_policy union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p       - IFCS attribute pointer
 * @param [in,out] ipt_policy_p - return ipt_policy value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ipt_policy_get(ifcs_attr_t *attr_p, ifcs_ipt_policy_t *ipt_policy_p);

/**
 * @brief Set the flex_stats_attributes union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p                  - IFCS attribute pointer
 * @param [in]     flex_stats_attributes_p - flex_stats_attributes
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_flex_stats_attributes_set(ifcs_attr_t *attr_p, ifcs_flex_stats_attributes_t *flex_stats_attributes_p);

/**
 * @brief Get the flex_stats_attributes union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p                  - IFCS attribute pointer
 * @param [in,out] flex_stats_attributes_p - return flex_stats_attributes value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_flex_stats_attributes_get(ifcs_attr_t *attr_p, ifcs_flex_stats_attributes_t *flex_stats_attributes_p);

/**
 * @brief Set the acl_action_value union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p             - IFCS attribute pointer
 * @param [in]     acl_action_value_p - acl_action_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_acl_action_value_set(ifcs_attr_t *attr_p, ifcs_acl_action_value_t *acl_action_value_p);

/**
 * @brief Get the acl_action_value union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p             - IFCS attribute pointer
 * @param [in,out] acl_action_value_p - return acl_action_value value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_acl_action_value_get(ifcs_attr_t *attr_p, ifcs_acl_action_value_t *acl_action_value_p);

/**
 * @brief Set the flex_stats_pkt_attr_map_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p                         - IFCS attribute pointer
 * @param [in]     flex_stats_pkt_attr_map_list_p - flex_stats_pkt_attr_map_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_flex_stats_pkt_attr_map_list_set(ifcs_attr_t *attr_p, ifcs_flex_stats_pkt_attr_map_list_t *flex_stats_pkt_attr_map_list_p);

/**
 * @brief Get the flex_stats_pkt_attr_map_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p                         - IFCS attribute pointer
 * @param [in,out] flex_stats_pkt_attr_map_list_p - return flex_stats_pkt_attr_map_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_flex_stats_pkt_attr_map_list_get(ifcs_attr_t *attr_p, ifcs_flex_stats_pkt_attr_map_list_t *flex_stats_pkt_attr_map_list_p);

/**
 * @brief Set the vlan_tag_action union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p            - IFCS attribute pointer
 * @param [in]     vlan_tag_action_p - vlan_tag_action
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_vlan_tag_action_set(ifcs_attr_t *attr_p, ifcs_vlan_tag_action_t *vlan_tag_action_p);

/**
 * @brief Get the vlan_tag_action union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p            - IFCS attribute pointer
 * @param [in,out] vlan_tag_action_p - return vlan_tag_action value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_vlan_tag_action_get(ifcs_attr_t *attr_p, ifcs_vlan_tag_action_t *vlan_tag_action_p);

/**
 * @brief Set the fpf_match_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p           - IFCS attribute pointer
 * @param [in]     fpf_match_list_p - fpf_match_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_fpf_match_list_set(ifcs_attr_t *attr_p, ifcs_fpf_match_list_t *fpf_match_list_p);

/**
 * @brief Get the fpf_match_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p           - IFCS attribute pointer
 * @param [in,out] fpf_match_list_p - return fpf_match_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_fpf_match_list_get(ifcs_attr_t *attr_p, ifcs_fpf_match_list_t *fpf_match_list_p);

/**
 * @brief Set the fpf_extraction_cmd_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p                    - IFCS attribute pointer
 * @param [in]     fpf_extraction_cmd_list_p - fpf_extraction_cmd_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_fpf_extraction_cmd_list_set(ifcs_attr_t *attr_p, ifcs_fpf_extraction_cmd_list_t *fpf_extraction_cmd_list_p);

/**
 * @brief Get the fpf_extraction_cmd_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p                    - IFCS attribute pointer
 * @param [in,out] fpf_extraction_cmd_list_p - return fpf_extraction_cmd_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_fpf_extraction_cmd_list_get(ifcs_attr_t *attr_p, ifcs_fpf_extraction_cmd_list_t *fpf_extraction_cmd_list_p);

/**
 * @brief Set the devport_an_bp_tech_ability_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p                            - IFCS attribute pointer
 * @param [in]     devport_an_bp_tech_ability_list_p - devport_an_bp_tech_ability_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_devport_an_bp_tech_ability_list_set(ifcs_attr_t *attr_p, ifcs_devport_an_bp_tech_ability_list_t *devport_an_bp_tech_ability_list_p);

/**
 * @brief Get the devport_an_bp_tech_ability_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p                            - IFCS attribute pointer
 * @param [in,out] devport_an_bp_tech_ability_list_p - return devport_an_bp_tech_ability_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_devport_an_bp_tech_ability_list_get(ifcs_attr_t *attr_p, ifcs_devport_an_bp_tech_ability_list_t *devport_an_bp_tech_ability_list_p);

/**
 * @brief Set the extended_field_value union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p                 - IFCS attribute pointer
 * @param [in]     extended_field_value_p - extended_field_value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_extended_field_value_set(ifcs_attr_t *attr_p, ifcs_extended_field_value_t *extended_field_value_p);

/**
 * @brief Get the extended_field_value union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p                 - IFCS attribute pointer
 * @param [in,out] extended_field_value_p - return extended_field_value value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_extended_field_value_get(ifcs_attr_t *attr_p, ifcs_extended_field_value_t *extended_field_value_p);

/**
 * @brief Set the mac_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p     - IFCS attribute pointer
 * @param [in]     mac_list_p - mac_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_mac_list_set(ifcs_attr_t *attr_p, ifcs_mac_list_t *mac_list_p);

/**
 * @brief Get the mac_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p     - IFCS attribute pointer
 * @param [in,out] mac_list_p - return mac_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_mac_list_get(ifcs_attr_t *attr_p, ifcs_mac_list_t *mac_list_p);

/**
 * @brief Set the ptp_time union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p     - IFCS attribute pointer
 * @param [in]     ptp_time_p - ptp_time
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ptp_time_set(ifcs_attr_t *attr_p, ifcs_ptp_time_t *ptp_time_p);

/**
 * @brief Get the ptp_time union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p     - IFCS attribute pointer
 * @param [in,out] ptp_time_p - return ptp_time value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ptp_time_get(ifcs_attr_t *attr_p, ifcs_ptp_time_t *ptp_time_p);

/**
 * @brief Set the ptp_timeoffset union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p           - IFCS attribute pointer
 * @param [in]     ptp_timeoffset_p - ptp_timeoffset
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ptp_timeoffset_set(ifcs_attr_t *attr_p, ifcs_ptp_timeoffset_t *ptp_timeoffset_p);

/**
 * @brief Get the ptp_timeoffset union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p           - IFCS attribute pointer
 * @param [in,out] ptp_timeoffset_p - return ptp_timeoffset value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ptp_timeoffset_get(ifcs_attr_t *attr_p, ifcs_ptp_timeoffset_t *ptp_timeoffset_p);

/**
 * @brief Set the ptp_policy union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p       - IFCS attribute pointer
 * @param [in]     ptp_policy_p - ptp_policy
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ptp_policy_set(ifcs_attr_t *attr_p, ifcs_ptp_policy_t *ptp_policy_p);

/**
 * @brief Get the ptp_policy union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p       - IFCS attribute pointer
 * @param [in,out] ptp_policy_p - return ptp_policy value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_ptp_policy_get(ifcs_attr_t *attr_p, ifcs_ptp_policy_t *ptp_policy_p);

/**
 * @brief Set the devport_speed_list union member in value field of ifcs_attr_t structure
 *
 * @param [in,out] attr_p               - IFCS attribute pointer
 * @param [in]     devport_speed_list_p - devport_speed_list
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_devport_speed_list_set(ifcs_attr_t *attr_p, ifcs_devport_speed_list_t *devport_speed_list_p);

/**
 * @brief Get the devport_speed_list union member in value field of ifcs_attr_t structure
 *
 * @param [in]     attr_p               - IFCS attribute pointer
 * @param [in,out] devport_speed_list_p - return devport_speed_list value
 * @return ifcs_status_t
 */
ifcs_status_t ifcs_attr_t_value_devport_speed_list_get(ifcs_attr_t *attr_p, ifcs_devport_speed_list_t *devport_speed_list_p);

#endif /* __IFCS_TYPES_H__ */
