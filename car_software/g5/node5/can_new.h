#include "integer.h"

extern st_cmd_t tx_remote_msg;

/* TEST VAR */
extern volatile hej;
/* TEST VAR */


U8 can_send_non_blocking(U8 msg_id, void* msg, U8 data_length);
