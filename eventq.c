/* Name: eventq.c */
/* Description: */
/* Author: John Houlihan */

/**
* MIT License
*
* Copyright (c) 2026 John Houlihan
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include "eventq.h"
#include <stdint.h>  /* uint8_t */


#define EVENTQ_SIZE 64


static eventq_t eventq;
static event_t event_queue[EVENTQ_SIZE] = {0};


/**
 * @brief Initialize eventq_t structure passed by pointer.
 * @note In-depth description of the function
 *
 * @param self  An instance of eventq_t
 * @return
 */
eventq_status_t eventq_init()
{
    eventq.size = EVENTQ_SIZE;
    eventq.capacity = 0;
    eventq.queue = event_queue;
    for (int i = 0; i < eventq.size; i++)
    {
        eventq.queue[i] = EVENT_NULL;
    }
    return EVENTQ_SUCCESS;
}


/**
 * @brief A brief explanation of the function
 *
 * @param[in] self  An instance of eventq_t
 * @return
 */
eventq_t* eventq_get_instance()
{
    return &eventq;
}


/**
 * @brief Flush the event queue
 *
 * @param[in] self  An instance of eventq_t
 * @return
 */
eventq_status_t eventq_flush()
{
    return EVENTQ_SUCCESS;
}


/**
 * @brief Put an item in the queue
 *
 * @param[in]  self  An instance of eventq_t
 * @param[in] event
 * @return
 */
eventq_status_t eventq_enqueue(event_t event)
{
    if (eventq.capacity >= EVENTQ_SIZE)
    {
        return EVENTQ_FULL_QUEUE;
    }
    eventq.queue[eventq.capacity] = event;
    eventq.capacity++;
    return EVENTQ_SUCCESS;
}


/**
 * @brief Get the next item in the queue
 *
 * @param[in]   self  An instance of eventq_t
 * @param[out] event
 * @return
 */
eventq_status_t eventq_dequeue(event_t* event)
{
    if (eventq.capacity <= 0)
    {
        return EVENTQ_EMTPY_QUEUE;
    }
    *event = eventq.queue[0];
    for (int i = 0; i + 1 < eventq.capacity; i++)
    {
        eventq.queue[i] = eventq.queue[i + 1];
    }
    eventq.queue[eventq.capacity - 1] = EVENT_NULL;
    eventq.capacity--;
    return EVENTQ_SUCCESS;
}


/**
 * @brief Get the number of items in the queue
 *
 * @param[in]      self  An instance of eventq_t
 * @param[out] capacity  the number of items in the queue
 * @return
 */
uint8_t eventq_get_capacity()
{
    return eventq.capacity;
}
