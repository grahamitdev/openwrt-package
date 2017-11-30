/*************************************************************************
 *
    > File Name: user_api.h
    > Author: lunan
    > Mail: 6616@shuncom.com 
    > Created Time: 2015年09月11日 星期五 13时32分55秒
 ************************************************************************/

#ifndef _USER_API_H_
#define _USER_API_H_

#ifdef __cplusplus
extern "C"
{
#endif


#include "user_types.h"
#include <sys/types.h>
#include <stdint.h>
#include "alink_export_zigbee.h"


extern int bytes2hexStr(const unsigned char *buf,char *hexStr,int bufLen);

extern int hexStr2bytes(const char *hexStr,unsigned char *buf,int bufLen);

extern void zha_get_ieeeaddr_by_string(char *ieeeaddr_string,uint8_t *extAddr);

extern Zstatus_t zigbee_init(char *dbname);

extern void zigbee_loop(void);

/* devices */

extern void device_scanNet(void);

extern void device_getDevicesList(void);

extern Zstatus_t device_getDeviceClusterId(uint8_t ieee_addr[8],uint8_t endpoint_id,uint16_t clusterId,uint16_t attribute_id);

extern uint8_t device_getDevice(uint8_t *ieeeAddr,deviceInfo_t **device);

extern uint16_t device_getDevicesList_fill(deviceInfo_t **devices);

extern Zstatus_t device_setDeviceAttr(uint8_t *ieeeAddr,uint8_t endpointId,char *attrName,void *attrValue);

extern Zstatus_t device_sendDeviceCmd(uint8_t *ieeeAddr,uint8_t endpointId,uint16_t clusterId,uint8_t cmdId,uint16 cmdFormatLen, uint8 *cmdFormat );

extern Zstatus_t device_writeDeviceAttr(uint8_t *ieeeAddr,uint8_t endpointId,uint16_t clusterId,uint16_t attrId,uint8_t dataType,void *data);

extern Zstatus_t device_setDeviceState(deviceBasic_t *deviceBasic,deviceState_t *deviceState);

extern Zstatus_t device_setPermitJoin(uint8_t *ieeeaddr,uint8_t duration);

extern Zstatus_t device_leaveReq(uint8_t *ieeeaddr);

extern void device_refreshHeartbeat(void);

extern void device_loadManufacturerSupperversion(char *ManufacturerName,char *ModelId,uint16_t supperversion);

/* white list */

extern Zstatus_t device_cleanWhitelist(void);

extern Zstatus_t device_writeWhitelist(uint8_t *ieeeaddr);

extern Zstatus_t device_deleteWhitelist(uint8_t *ieeeaddr);

extern uint16_t device_getWhitelist(uint8_t *ieeeaddr);

extern void device_enableWhitelist(uint8_t status);

extern Zstatus_t user_quanshiWriteData(uint8_t *ieeeAddr,uint16_t clusterId,uint8_t *data,uint8_t len);
/* group */

extern uint16_t group_create(char *groupName);

extern Zstatus_t group_removeAllDevices(uint16_t groupId);

extern Zstatus_t group_addDevice(uint16_t groupId, groupMemberInfo_t *groupMember);

extern Zstatus_t group_viewDevice(uint16_t groupId, groupMemberInfo_t *groupMember);

extern Zstatus_t group_removeDevice(uint16_t groupId, groupMemberInfo_t *groupMember);

extern Zstatus_t group_changeName(uint16_t groupId,char *name);

extern Zstatus_t group_setDeviceAttr(uint16_t groupId,char *attrName,void *attrValue);

extern groupInfo_t *group_getList(uint16_t *nums);

extern Zstatus_t group_get(uint16_t id,groupInfo_t *group);

extern Zstatus_t group_del(uint16_t id);
/* add new scene, and return scene id. */
extern uint8_t scene_create(char * sceneName,uint16_t groupID,uint16_t iconId);

extern Zstatus_t scene_set(uint8_t id,char *name,uint16_t groupId,uint16_t iconId);

extern Zstatus_t scene_store(uint8_t sceneId);

extern Zstatus_t scene_recall(uint8_t sceneId);

extern sceneInfo_t *scene_getList(uint16_t *nums);

extern Zstatus_t scene_del(uint8_t id);

/* add new rule, and return rule id. */
extern uint16_t rule_create(rule_t_t * newRule);

extern Zstatus_t rule_enableRule(uint16_t ruleId,uint8_t status);

extern rule_t_t * rule_find(uint16_t ruleId);

extern void rule_update(rule_t_t  *rule);

extern Zstatus_t rule_del(uint16_t id);

extern void coord_getInfo(coordInfo_t *coordInfo);

extern void coord_changeChannel(uint8_t channel);

extern void coord_cleanDeviceList(void);

extern void coord_resetFactNew(void);

/*
* @brif 
*	ManufacturerName:³§¼ÒÃû£¬¿ÉÒÔ²»Ìî£¬²»ÌîµÄÊ±ºòÖÃNULL
*	ModelId:Ò»¶¨ÒªÌî
*	supperversion:Éè±¸µÄÐÄÌøÖÜÆÚ£¬ÉèÎª0xfffe±íÊ¾¸ÃÀàÉè±¸Ã»ÓÐÐÄÌø
*
*/
extern void device_loadManufacturerSupperversion(char *ManufacturerName,char *ModelId,uint16_t supperversion);

extern Zstatus_t Zap_znpIncoming(uint8_t *buf,uint8_t len);

extern uint16_t device_getNwkAddrByIeeeAddr(uint8_t *ieeeAddr);

extern char *lib_compileTime(void);


#ifdef __cplusplus
}
#endif


#endif
