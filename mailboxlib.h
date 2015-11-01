/* ================================================= *
 * Define prototypes for message and mailbox structs *
 * ================================================= */

#ifndef _MAILBOXLIB_H_
#define _MAILBOXLIB_H_

#include <stdlib.h>
#include <stdio.h>
#include <lib.h>
#include <string.h>

#define MAX_MESSAGE_COUNT 16
#define OK 0
#define ERROR -1

int create_mailbox();

/* Message LinkedList
 * recipients - recipients of this message
 * message - the message value
 * next - pointer to next message
 */

typedef struct message_struct {
  int *recipients;
  char *message;
  struct message_struct *prev;
  struct message_struct *next;
} message_t;

/* Mailbox
 * number_of_messages - current number of messages in the mailbox (limit is 16)
 * head - pointer to head of message linked list
 * last_msg - pointer to last message of the linked list
 */

typedef struct {
  int number_of_messages;
  message_t *head;
} mailbox_t;


int send_message(char *messageData, int *recipients)
{
	message m;
	int arraySize = sizeof(recipients);
	int i;
	char recipientsString[128];  // 6 [5 from pid + 1 from separator] * 16, will be always lower than 128


	for (i = 0; i < arraySize; i ++)
	{
		snprintf(recipientsString, 128, "%d", recipients[i]);
		strncat(recipientsString, " ", 1);
	}

	printf("Maping message %s to pids %s\n", messageData, recipientsString);

	m.m1_p1 = messageData;
	m.m1_p2 = recipientsString;

	return(_syscall(PM_DEPOSIT, 48, &m));
}



int recieve_message()
{

	return 0;
}

#endif
