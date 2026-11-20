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


/**
 * @brief Initialize eventq_t structure passed by pointer.
 * @note In-depth description of the function
 *
 * @param self  An instance of eventq_t
 * @return
 */
eventq_status_t eventq_init(eventq_t* self, event_t* queue, uint8_t size)
{
    self->size = size;
    self->capacity = 0;
    self->queue = queue;
    for (int i = 0; i < self->size; i++)
    {
        self->queue[i] = EVENT_NULL;
    }
    return EVENTQ_SUCCESS;
}


/**
 * @brief Flush the event queue
 *
 * @param[in] self  An instance of eventq_t
 * @return
 */
eventq_status_t eventq_flush(eventq_t* self)
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
eventq_status_t eventq_enqueue(eventq_t* self, event_t event)
{
    if (self->capacity >= EVENTQ_SIZE)
    {
        return EVENTQ_FULL_QUEUE;
    }
    self->queue[self->capacity] = event;
    self->capacity++;
    return EVENTQ_SUCCESS;
}


/**
 * @brief Get the next item in the queue
 *
 * @param[in]   self  An instance of eventq_t
 * @param[out] event
 * @return
 */
eventq_status_t eventq_dequeue(eventq_t* self, event_t* event)
{
    if (self->capacity <= 0)
    {
        return EVENTQ_EMTPY_QUEUE;
    }
    *event = self->queue[0];
    for (int i = 0; i + 1 < self->capacity; i++)
    {
        self->queue[i] = self->queue[i + 1];
    }
    self->queue[self->capacity - 1] = EVENT_NULL;
    self->capacity--;
    return EVENTQ_SUCCESS;
}


/**
 * @brief Get the number of items in the queue
 *
 * @param[in]      self  An instance of eventq_t
 * @param[out] capacity  the number of items in the queue
 * @return
 */
eventq_status_t eventq_get_capacity(eventq_t* self, uint8_t* capacity)
{
    *capacity = self->capacity;
    return EVENTQ_SUCCESS;
}
