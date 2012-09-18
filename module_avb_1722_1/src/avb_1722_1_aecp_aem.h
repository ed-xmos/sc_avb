#ifndef AVB_1722_1_AECP_AEM_H_
#define AVB_1722_1_AECP_AEM_H_

#include "avb_1722_1_protocol.h"
#include "avb_1722_1_default_conf.h"

/* 7.4.2.1. READ_DESCRIPTOR Command Format */

typedef struct {
	unsigned char configuration[2];
	unsigned char reserved[2];
	unsigned char descriptor_type[2];
	unsigned char descriptor_id[2];
} avb_1722_1_aem_read_descriptor_command_t;

/* 7.4.2.2. READ_DESCRIPTOR Response Format */
typedef struct {
	unsigned char configuration[2];
	unsigned char reserved[2];
	unsigned char descriptor[512];
} avb_1722_1_aem_read_descriptor_response_t;

/* 7.4.1. ACQUIRE_ENTITY Command */
typedef struct {
	unsigned char flags[4];
	unsigned char owner_guid[8];
	unsigned char descriptor_type[2];
	unsigned char descriptor_id[2];
} avb_1722_1_aem_acquire_entity_command_t;

#define AEM_ACQUIRE_ENTITY_PERSISTENT_FLAG(cmd)		((cmd)->flags[3] & 1)

/* 7.4.2. LOCK_ENTITY Command */
typedef struct {
	unsigned char flags[4];
	unsigned char locked_guid[8];
} avb_1722_1_aem_lock_entity_command_t;

#endif /* AVB_1722_1_AECP_AEM_H_ */
