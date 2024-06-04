
struct Integer_Array_List
{
    int is_initialized;
    int is_memory_free;
    int current_item_count;
    int maximum_item_count;
    int *pointer;
};

void initialize_integer_array_list(struct Integer_Array_List *integer_array_list, int maximum_item_count)
{
    integer_array_list->is_initialized = 1;
    integer_array_list->is_memory_free = 0;
    integer_array_list->current_item_count = 0;
    integer_array_list->maximum_item_count = maximum_item_count;
    integer_array_list->pointer = (int *)calloc(1, sizeof(int));
}

int find_current_middle_index(struct Integer_Array_List *integer_array_list)
{
    int current_middle_index;
    if (integer_array_list->current_item_count % 2 == 0)
    {
        current_middle_index = integer_array_list->current_item_count / 2 - 1;
    }
    else
    {
        current_middle_index = integer_array_list->current_item_count / 2;
    }
    return current_middle_index;
}

void free_memory(struct Integer_Array_List *integer_array_list)
{
    free(integer_array_list->pointer);
    integer_array_list->is_memory_free = 1;
}

void append_item_at_the_first_index(struct Integer_Array_List *integer_array_list, int item)
{
    integer_array_list->current_item_count += 1;
    integer_array_list->pointer = (int *)realloc(integer_array_list->pointer,
                                                 sizeof(int) * (integer_array_list->current_item_count));
    for (int current_index = integer_array_list->current_item_count - 2;
         current_index >= 0; current_index -= 1)
    {
        *(integer_array_list->pointer + (current_index + 1)) = *(integer_array_list->pointer + current_index);
    }
    *integer_array_list->pointer = item;
}

void append_item_at_index(struct Integer_Array_List *integer_array_list, int item, int target_index)
{
    integer_array_list->current_item_count += 1;
    integer_array_list->pointer = (int *)realloc(integer_array_list->pointer,
                                                 sizeof(int) * (integer_array_list->current_item_count));
    for (int current_index = integer_array_list->current_item_count - 2;
         current_index >= target_index; current_index -= 1)
    {
        *(integer_array_list->pointer + (current_index + 1)) = *(integer_array_list->pointer + current_index);
    }
    *(integer_array_list->pointer + target_index) = item;
}

void append_item_at_the_last_index(struct Integer_Array_List *integer_array_list, int item)
{
    integer_array_list->current_item_count += 1;
    integer_array_list->pointer = (int *)realloc(integer_array_list->pointer,
                                                 sizeof(int) * (integer_array_list->current_item_count));
    *(integer_array_list->pointer + (integer_array_list->current_item_count - 1)) = item;
}

void remove_item_at_the_first_index(struct Integer_Array_List *integer_array_list)
{
    integer_array_list->current_item_count -= 1;
    for (int current_index = 0; current_index < integer_array_list->current_item_count;
         current_index += 1)
    {
        *(integer_array_list->pointer + current_index) = *(integer_array_list->pointer + current_index + 1);
    }
    *(integer_array_list->pointer + integer_array_list->current_item_count) = (int)NULL;
    integer_array_list->pointer = (int *)realloc(integer_array_list->pointer,
                                                 sizeof(int) * (integer_array_list->current_item_count));
}

void remove_item_at_index(struct Integer_Array_List *integer_array_list, int target_index)
{
    integer_array_list->current_item_count -= 1;
    *(integer_array_list->pointer + target_index) = (int)NULL;
    for (int current_index = target_index; current_index < integer_array_list->current_item_count;
         current_index += 1)
    {
        *(integer_array_list->pointer + current_index) = *(integer_array_list->pointer + current_index + 1);
    }
    integer_array_list->pointer = (int *)realloc(integer_array_list->pointer,
                                                 sizeof(int) * (integer_array_list->current_item_count));
}

void remove_item_at_the_last_index(struct Integer_Array_List *integer_array_list)
{
    integer_array_list->current_item_count -= 1;
    *(integer_array_list->pointer + integer_array_list->current_item_count) = (int)NULL;
    integer_array_list->pointer = (int *)realloc(integer_array_list->pointer,
                                                 sizeof(int) * (integer_array_list->current_item_count));
}

void reverse_order(struct Integer_Array_List *integer_array_list)
{
    int middle_index = find_current_middle_index(integer_array_list);
    for (int current_index = 0; current_index <= middle_index; current_index += 1)
    {
        int *pointer_rightwise_item = integer_array_list->pointer + (integer_array_list->current_item_count - current_index - 1);
        int *pointer_leftwise_item = integer_array_list->pointer + current_index;
        int focused_item = *(pointer_rightwise_item);
        *(pointer_rightwise_item) = *(pointer_leftwise_item);
        *(pointer_leftwise_item) = focused_item;
    }
}

int find_index_of_item(struct Integer_Array_List *integer_array_list, int item)
{
    for (int current_index = 0; current_index < integer_array_list->current_item_count;
         current_index += 1)
    {
        if (*(integer_array_list->pointer + current_index) == item)
        {
            return current_index;
        }
    }
    return -1;
}

int *generate_array_copy(struct Integer_Array_List *integer_array_list)
{
    int *pointer_array_copy = (int *)calloc(integer_array_list->current_item_count, sizeof(int));
    for (int current_index = 0; current_index < integer_array_list->current_item_count; current_index += 1)
    {
        *(pointer_array_copy + current_index) = *(integer_array_list->pointer + current_index);
    }
    return pointer_array_copy;
}

void print_properties(struct Integer_Array_List *integer_array_list)
{
    printf("current_item_count: %d\n", integer_array_list->current_item_count);
    printf("maximum_item_count: %d\n", integer_array_list->maximum_item_count);
    printf("is_memory_free: %d\n", integer_array_list->is_memory_free);
    printf("is_initialized: %d\n", integer_array_list->is_initialized);
    printf("items: [");
    for (int current_index = 0; current_index < integer_array_list->current_item_count;
         current_index += 1)
    {
        printf("%d", *(integer_array_list->pointer + current_index));
        if (current_index < integer_array_list->current_item_count - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}