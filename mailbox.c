/* File mailbox.c */
/* Define system calls to the mailbox */

#include "mailboxlib.h"

static mailbox_t *mailbox;

int create_mailbox(){
	mailbox = malloc(sizeof(mailbox_t));
	mailbox->head = malloc(sizeof(message_t));

	// Sentinel
	message_t *head = malloc(sizeof(message_t));
	head->message = "HEAD";
	head->prev = head;
	head->next = head;

	mailbox->head = head;
	mailbox->number_of_messages = 0;

	return OK;
}

/* Creates mailbox if there is none
 * Add message to mailbox (if mailbox is not full)
 * Returns OK if message was successfully added
 * Returns ERROR if mailbox is full
 *
 * TODO: Remove parameters and use a message type
 */
int add_to_mailbox(char *message, int *recipients)
{

	//If the mailbox doesn't exist, we create it first
	if (!mailbox)
	{
		create_mailbox();
	}

	if (mailbox->number_of_messages < MAX_MESSAGE_COUNT)
	{
	  	message_t *new_message = malloc(sizeof(message_t));
		new_message->recipients = recipients;
		new_message->message = message;

		new_message->next = mailbox->head;
		new_message->prev = mailbox->head->prev;

		mailbox->head->prev->next = new_message;
		mailbox->head->prev = new_message;

		mailbox->number_of_messages += 1;
	}
	else
	{
		printf("Error: mailbox is full\n");
		return ERROR;
	}

	return OK;
}

int get_from_mailbox(char *message, int recipient)
{


	return OK;
}
