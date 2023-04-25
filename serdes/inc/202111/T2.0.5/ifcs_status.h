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
 * @file  ifcs_status.h
 * @brief IFCS status codes
 * +------+------+----+----+-------+------+
 * |Module|Object|Oper|Attr|ErrCode|Reason|
 * +------+------+----+----+-------+------+
 * |  7   |  4   | 6  |  8 |    2  |  5   | Bits
 * +------+------+----+----+-------+------+
 * | 128  |  16  | 64 | 256|    4  |  32  | Max
 * +------+------+----+----+-------+------+
 */

#ifndef __IFCS_STATUS_H__
#define __IFCS_STATUS_H__

#include "api/ifcs_module.h"
/*! Shift for IFCS Module */
#define IFCS_STATUS_MODULE_SHIFT 25

/*! Invalid moudle */
#define IFCS_STATUS_MODULE_INVALID (0x7f)

/*! Module mask */
#define IFCS_STATUS_MODULE_MASK ((uint32_t)IFCS_STATUS_MODULE_INVALID << IFCS_STATUS_MODULE_SHIFT)

/*! Shift for IFCS Object */
#define IFCS_STATUS_OBJECT_SHIFT 21

/*! Invalid object */
#define IFCS_STATUS_OBJECT_INVALID (0xf)

/*! Object Mask */
#define IFCS_STATUS_OBJECT_MASK (IFCS_STATUS_OBJECT_INVALID << IFCS_STATUS_OBJECT_SHIFT)

/*! Shift for IFCS Operation */
#define IFCS_STATUS_OPER_SHIFT 15

/*! Invalid operation */
#define IFCS_STATUS_OPER_INVALID (0x3f)

/*! Oper mask */
#define IFCS_STATUS_OPER_MASK (IFCS_STATUS_OPER_INVALID << IFCS_STATUS_OPER_SHIFT)

/*! Shift for IFCS Attr */
#define IFCS_STATUS_ATTR_SHIFT 7

/*! Invalid attritbute */
#define IFCS_STATUS_ATTR_INVALID (0xff)

/*! Attr mask */
#define IFCS_STATUS_ATTR_MASK (IFCS_STATUS_ATTR_INVALID << IFCS_STATUS_ATTR_SHIFT)

/*! Shift for IFCS Status */
#define IFCS_STATUS_REASON_SHIFT 0

/*! Shift for IFCS error code */
#define IFCS_STATUS_ERROR_CODE_SHIFT 0x5

/*! Invalid reason */
#define IFCS_STATUS_REASON_INVALID (0x1f)

/*! Reason mask */
#define IFCS_STATUS_REASON_MASK (IFCS_STATUS_REASON_INVALID << IFCS_STATUS_REASON_SHIFT)

/*! Invalid reason */
#define IFCS_STATUS_ERROR_CODE_INVALID (0x3)

/*! Error code  mask */
#define IFCS_STATUS_ERROR_CODE_MASK (IFCS_STATUS_ERROR_CODE_INVALID << IFCS_STATUS_ERROR_CODE_SHIFT)

/*! Create an IFCS object of a given type */
#define IFCS_STATUS(mod, obj, oper, attr, code)                                                                                                                                                                                                                                                            \
    (ifcs_status_t)(ifcs_status_encoding_enabled() ? ((mod << IFCS_STATUS_MODULE_SHIFT) | (obj << IFCS_STATUS_OBJECT_SHIFT) | (oper << IFCS_STATUS_OPER_SHIFT) | (attr << IFCS_STATUS_ATTR_SHIFT) | (code << IFCS_STATUS_REASON_SHIFT)) : (code << IFCS_STATUS_REASON_SHIFT))

#define IFCS_STATUS_WITH_ERROR(status, errcode) (ifcs_status_t)((errcode << IFCS_STATUS_ERROR_CODE_SHIFT) | status)

/*! IFCS Status Module */
#define IFCS_STATUS_MODULE(status) ((status & IFCS_STATUS_MODULE_MASK) >> IFCS_STATUS_MODULE_SHIFT)

/*! IFCS Status Object */
#define IFCS_STATUS_OBJECT(status) ((status & IFCS_STATUS_OBJECT_MASK) >> IFCS_STATUS_OBJECT_SHIFT)

/*! IFCS Status Operation */
#define IFCS_STATUS_OPER(status) ((status & IFCS_STATUS_OPER_MASK) >> IFCS_STATUS_OPER_SHIFT)

/*! IFCS Status Attr */
#define IFCS_STATUS_ATTR(status) ((status & IFCS_STATUS_ATTR_MASK) >> IFCS_STATUS_ATTR_SHIFT)

/*! IFCS Status Status */
#define IFCS_STATUS_REASON(status) ((status & IFCS_STATUS_REASON_MASK) >> IFCS_STATUS_REASON_SHIFT)

/*! IFCS Status Error Code  */
#define IFCS_STATUS_ERROR_CODE(status) ((status & IFCS_STATUS_ERROR_CODE_MASK) >> IFCS_STATUS_ERROR_CODE_SHIFT)

#define GENERATE_ENUM(ENUM)     ENUM,
#define GENERATE_STRING(STRING) #STRING,

/**
 *  IFCS_SUCCESS             = 0  Success Status
 *  IFCS_UNINIT              = 1  Uninitialized
 *  IFCS_BUSY                = 2  Resource in Use
 *  IFCS_CONFIG              = 3  Invalid Configuration
 *  IFCS_MEMORY              = 4  Out of Memory Errors
 *  IFCS_PARAM               = 5  Invalid Parameter
 *  IFCS_EXIST               = 6  Entry already exists
 *  IFCS_MULTI_EXIST         = 7  Multiple Entries exists
 *  IFCS_ENTRY_REPLACED      = 8  Entry Replaced
 *  IFCS_LENGTH_MISMATCH     = 9  Entry Length Mismatch
 *  IFCS_NOTFOUND            = 10 Entry not found in device
 *  IFCS_INVAL               = 11 Invalid argument
 *  IFCS_UNSUPPORTED         = 12 Unsupported API or configuration
 *  IFCS_RESOURCE_FULL       = 13 Resouce Full condition
 *  IFCS_TIMEOUT             = 14 Timeout Error condition
 *  IFCS_DEVICE_ACCESS_ERROR = 15 Device access failures
 *  IFCS_DRIVER_ERROR        = 16 Driver errors
 */
#define FOREACH_IFCS_REASON(_IFCS_STATUS)                                                                                                                                                                                                                                                                  \
    _IFCS_STATUS(IFCS_SUCCESS)                                                                                                                                                                                                                                                                             \
    _IFCS_STATUS(IFCS_UNINIT)                                                                                                                                                                                                                                                                              \
    _IFCS_STATUS(IFCS_BUSY)                                                                                                                                                                                                                                                                                \
    _IFCS_STATUS(IFCS_CONFIG)                                                                                                                                                                                                                                                                              \
    _IFCS_STATUS(IFCS_MEMORY)                                                                                                                                                                                                                                                                              \
    _IFCS_STATUS(IFCS_PARAM)                                                                                                                                                                                                                                                                               \
    _IFCS_STATUS(IFCS_EXIST)                                                                                                                                                                                                                                                                               \
    _IFCS_STATUS(IFCS_MULTI_EXIST)                                                                                                                                                                                                                                                                         \
    _IFCS_STATUS(IFCS_ENTRY_REPLACED)                                                                                                                                                                                                                                                                      \
    _IFCS_STATUS(IFCS_LENGTH_MISMATCH)                                                                                                                                                                                                                                                                     \
    _IFCS_STATUS(IFCS_NOTFOUND)                                                                                                                                                                                                                                                                            \
    _IFCS_STATUS(IFCS_INVAL)                                                                                                                                                                                                                                                                               \
    _IFCS_STATUS(IFCS_UNSUPPORTED)                                                                                                                                                                                                                                                                         \
    _IFCS_STATUS(IFCS_RESOURCE_FULL)                                                                                                                                                                                                                                                                       \
    _IFCS_STATUS(IFCS_TIMEOUT)                                                                                                                                                                                                                                                                             \
    _IFCS_STATUS(IFCS_DEVICE_ACCESS_ERROR)                                                                                                                                                                                                                                                                 \
    _IFCS_STATUS(IFCS_DRIVER_ERROR)

/**
 * @brief IFCS Status codes
 */
typedef enum ifcs_reason_e { FOREACH_IFCS_REASON(GENERATE_ENUM) } ifcs_reason_t;

typedef int ifcs_status_t;

const char *ifcs_status_to_string(ifcs_status_t status);

int ifcs_status_encoding_enabled(void);

ifcs_status_t ifcs_status_set_encoding(int enable);

#endif /* __IFCS_STATUS_H__ */
