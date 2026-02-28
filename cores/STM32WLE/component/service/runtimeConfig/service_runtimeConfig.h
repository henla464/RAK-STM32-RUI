/**
 * @file        service_runtimeConfig.h
 * @brief       Provide runtime config setting.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2023.03
 */

#ifndef __SERVICE_RUNTIMECONFIG_H__
#define __SERVICE_RUNTIMECONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif


#ifndef NO_LORA_SUPPORT
typedef struct runtimeConfigP2P_s {
    uint32_t frequency;
    uint8_t spreading_factor;
    uint32_t bandwidth;
    uint32_t fsk_rxbw;
    uint8_t coding_rate;
    uint16_t preamble_length;
    uint8_t txpower;
    bool low_data_rate_optimize;
    bool crc_on;
    bool rxgain;
    bool drf1268dscompatmode;
    bool sendack;
    uint8_t payload_len;
    bool fix_length_payload;
} runtimeConfigP2P_t;

bool get_useRuntimeConfigP2P(void);
void set_useRuntimeConfigP2P(bool useRuntimeConfig);
bool get_runtimeConfigP2P(runtimeConfigP2P_t *configP2P);
bool set_runtimeConfigP2P(runtimeConfigP2P_t *configP2P);
#endif


#ifdef __cplusplus
}
#endif

#endif  // __SERVICE_RUNTIMECONFIG_H__
