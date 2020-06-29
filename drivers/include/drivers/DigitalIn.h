/* mbed Microcontroller Library
 * Copyright (c) 2006-2020 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MBED_DIGITALIN_H
#define MBED_DIGITALIN_H

#include "platform/platform.h"

#include "hal/gpio_api.h"

/**
 * Option to make certain class functions virtual for advanced polymorphism.
 * Disabled by default for size and speed optimization.
 */
#ifndef MBED_CONF_DRIVERS_VIRTUALIZE_DIGITALIN
#define MBED_CONF_DRIVERS_VIRTUALIZE_DIGITALIN false
#endif

namespace mbed {
/**
 * \defgroup drivers_DigitalIn DigitalIn class
 * \ingroup drivers-public-api-gpio
 * @{
 */

/** A digital input, used for reading the state of a pin
 *
 * @note Synchronization level: Interrupt safe
 *
 * Example:
 * @code
 * // Flash an LED while a DigitalIn is true
 *
 * #include "mbed.h"
 *
 * DigitalIn enable(p5);
 * DigitalOut led(LED1);
 *
 * int main() {
 *     while(1) {
 *         if(enable) {
 *             led = !led;
 *         }
 *         ThisThread::sleep_for(250);
 *     }
 * }
 * @endcode
 */
class DigitalIn {

public:
    /** Create a DigitalIn connected to the specified pin
     *
     *  @param pin DigitalIn pin to connect to
     */
    DigitalIn(PinName pin) : gpio()
    {
        // No lock needed in the constructor
        gpio_init_in(&gpio, pin);
    }

    /** Create a DigitalIn connected to the specified pin
     *
     *  @param pin DigitalIn pin to connect to
     *  @param mode the initial mode of the pin
     */
    DigitalIn(PinName pin, PinMode mode) : gpio()
    {
        // No lock needed in the constructor
        gpio_init_in_ex(&gpio, pin, mode);
    }

    /** Class destructor, deinitialize the pin
     */
#if MBED_CONF_DRIVERS_VIRTUALIZE_DIGITALIN
    virtual ~DigitalIn()
#else
    ~DigitalIn()
#endif
    {
        gpio_free(&gpio);
    }

    /** Read the input, represented as 0 or 1 (int)
     *
     *  @returns
     *    An integer representing the state of the input pin,
     *    0 for logical 0, 1 for logical 1
     */
#if MBED_CONF_DRIVERS_VIRTUALIZE_DIGITALIN
    virtual int read()
#else
    int read()
#endif
    {
        // Thread safe / atomic HAL call
        return gpio_read(&gpio);
    }

    /** Set the input pin mode
     *
     *  @param pull PullUp, PullDown, PullNone, OpenDrain
     */
#if MBED_CONF_DRIVERS_VIRTUALIZE_DIGITALIN
    virtual void mode(PinMode pull);
#else
    void mode(PinMode pull);
#endif

    /** Return the output setting, represented as 0 or 1 (int)
     *
     *  @returns
     *    Non zero value if pin is connected to uc GPIO
     *    0 if gpio object was initialized with NC
     */
#if MBED_CONF_DRIVERS_VIRTUALIZE_DIGITALIN
    virtual int is_connected()
#else
    int is_connected()
#endif
    {
        // Thread safe / atomic HAL call
        return gpio_is_connected(&gpio);
    }

    /** An operator shorthand for read()
     * \sa DigitalIn::read()
     * @code
     *      DigitalIn  button(BUTTON1);
     *      DigitalOut led(LED1);
     *      led = button;   // Equivalent to led.write(button.read())
     * @endcode
     */
    operator int()
    {
        // Underlying read is thread safe
        return read();
    }

protected:
#if !defined(DOXYGEN_ONLY)
    gpio_t gpio;
#endif //!defined(DOXYGEN_ONLY)
};

/** @}*/

} // namespace mbed

#endif
