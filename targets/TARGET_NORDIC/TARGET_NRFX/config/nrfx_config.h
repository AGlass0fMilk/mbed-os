/*
 * Copyright (c) 2019 - 2020, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NRFX_CONFIG_H__
#define NRFX_CONFIG_H__

/**
 * Modification by mbed-os to configure interrupt priority settings
 */
#define PRIORITY_REALTIME       0
#define PRIORITY_EXTREMELY_HIGH 1
#define PRIORITY_VERY_HIGH      2
#define PRIORTY_HIGH            3
#define PRIORITY_MEDIUM_HIGH    4
#define PRIORITY_MEDIUM         5
#define PRIORITY_MEDIUM_LOW     6
#define PRIORITY_LOW            7
#define PRIORITY_THREAD         15

#if defined(NRF51)
    #include <nrfx_config_nrf51.h>
#elif defined(NRF52805_XXAA)
    #include <nrfx_config_nrf52805.h>
#elif defined(NRF52810_XXAA)
    #include <nrfx_config_nrf52810.h>
#elif defined(NRF52811_XXAA)
    #include <nrfx_config_nrf52811.h>
#elif defined(NRF52820_XXAA)
    #include <nrfx_config_nrf52820.h>
#elif defined(NRF52832_XXAA) || defined (NRF52832_XXAB)
    #include <nrfx_config_nrf52832.h>
#elif defined(NRF52833_XXAA)
    #include <nrfx_config_nrf52833.h>
#elif defined(NRF52840_XXAA)
    #include <nrfx_config_nrf52840.h>
#elif defined(NRF5340_XXAA_APPLICATION)
    #include <nrfx_config_nrf5340_application.h>
#elif defined(NRF5340_XXAA_NETWORK)
    #include <nrfx_config_nrf5340_network.h>
#elif defined(NRF9160_XXAA)
    #include <nrfx_config_nrf9160.h>
#else
    #error "Unknown device."
#endif

#endif // NRFX_CONFIG_H__
