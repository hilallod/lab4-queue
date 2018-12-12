#include "..\mp2-lab4-queue\Queue.h"

#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(TQueue<int> TQ(3));
}

