#include "list.h"

int        cycle_detector(const t_list *list)
{
	t_list *fast;
	t_list *slow;

	fast = (t_list *)list->next;
	slow = (t_list *)list;
	while (fast && fast->next)
	{
		if (fast == slow)
			return (1);
		fast = fast->next->next;
		slow = slow->next;
	}
	return (0);
}
