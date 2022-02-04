#ifndef INC_DEV_USART
#define INC_DEV_USART

#ifdef __cplusplus
extern "C" {
#endif

#include "core/actor.h"
#include <libopencm3/stm32/usart.h>

#define USART_RX_BUFFER_SIZE 64

/* Start of autogenerated OD types */
/* 0x6240: Transport USART 1
   Serial protocol */
typedef struct transport_usart_properties {
    uint8_t parameter_count;
    uint8_t dma_rx_unit;
    uint8_t dma_rx_stream;
    uint8_t dma_rx_channel;
    uint8_t dma_rx_circular_buffer_size;
    uint8_t dma_tx_unit;
    uint8_t dma_tx_stream;
    uint8_t dma_tx_channel;
    uint32_t baudrate;
    uint8_t databits;
    uint8_t phase;
} transport_usart_properties_t;
/* End of autogenerated OD types */

struct transport_usart {
    actor_t *actor;
    transport_usart_properties_t *properties;
    uint32_t clock;
    uint32_t address;
    uint32_t dma_tx_address;
    uint32_t dma_rx_address;
    actor_t *target_actor;
    void *target_argument;

    uint8_t *dma_rx_circular_buffer;
};

extern actor_class_t transport_usart_class;

int transport_usart_send(transport_usart_t *usart, char *data, int size);


/* Start of autogenerated OD accessors */
typedef enum transport_usart_properties_properties {
  TRANSPORT_USART_DMA_RX_UNIT = 0x01,
  TRANSPORT_USART_DMA_RX_STREAM = 0x02,
  TRANSPORT_USART_DMA_RX_CHANNEL = 0x03,
  TRANSPORT_USART_DMA_RX_CIRCULAR_BUFFER_SIZE = 0x04,
  TRANSPORT_USART_DMA_TX_UNIT = 0x05,
  TRANSPORT_USART_DMA_TX_STREAM = 0x06,
  TRANSPORT_USART_DMA_TX_CHANNEL = 0x07,
  TRANSPORT_USART_BAUDRATE = 0x08,
  TRANSPORT_USART_DATABITS = 0x09,
  TRANSPORT_USART_PHASE = 0x0A
} transport_usart_properties_properties_t;

/* 0x62XX0A: null */
#define transport_usart_set_phase(usart, value) actor_set_property_numeric(usart->actor, (uint32_t) value, sizeof(uint8_t), TRANSPORT_USART_PHASE)
#define transport_usart_get_phase(usart) *((uint8_t *) actor_get_property_pointer(usart->actor, &(uint8_t[sizeof(uint8_t)]{}), sizeof(uint8_t), TRANSPORT_USART_PHASE)
/* End of autogenerated OD accessors */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif