#include "..\mp2-lab4-queue\Queue.h"

#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_max_size)
{
	EXPECT_NO_THROW(TQueue <int> queue(5));
}
