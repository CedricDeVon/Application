
int *pointer_integer_array_list;
int is_initialized = 0;
int is_memory_free = 0;
int current_item_count = 0;
int maximum_item_count = 10;

void validate_pointer_existence()
{
    if (pointer_integer_array_list == NULL)
    {
        printf("ERROR: The integer array list pointer cannot be found!");
        exit(1);
    }
}

void validate_pointer_reinitialization()
{
    if (is_initialized)
    {
        printf("ERROR: Cannot re-initialize integer_array_list!");
        exit(1);
    }
}

void validate_pointer_uninitialization()
{
    if (!is_initialized)
    {
        printf("ERROR: The integer array list must be initialized!");
        exit(1);
    }
}

void validate_maximum_item_count_reached()
{
    if (current_item_count >= maximum_item_count)
    {
        printf("ERROR: Maximum item count reached!");
        exit(1);
    }
}

void validate_item_count_reached_0()
{
    if (current_item_count <= 0)
    {
        printf("ERROR: The integer array list is empty!");
        exit(1);
    }
}

void validate_target_index(int target_index)
{
    if (target_index < 0 || target_index >= current_item_count)
    {
        printf("ERROR: The target index must be greater than 0 or less than the current item count!");
        exit(1);
    }
}

int get_middle_index()
{
    validate_item_count_reached_0();

    int middle_index;
    if (current_item_count % 2 == 0)
    {
        middle_index = current_item_count / 2 - 1;
    }
    else
    {
        middle_index = current_item_count / 2;
    }
    return middle_index;
}

int *generate_array_copy()
{
    int *pointer_array_copy = (int *)calloc(current_item_count, sizeof(int));
    for (int current_index = 0; current_index < current_item_count; current_index += 1)
    {
        *(pointer_array_copy + current_index) = *(pointer_integer_array_list + current_index);
    }
    return pointer_array_copy;
}

void initialize_integer_array_list()
{
    pointer_integer_array_list = (int *)calloc(1, sizeof(int));
    validate_pointer_existence();
    validate_pointer_reinitialization();
    is_initialized = 1;
}

void free_memory()
{
    validate_pointer_uninitialization();

    free(pointer_integer_array_list);
    is_memory_free = 1;
}

void append_item_at_the_first_index(int item)
{
    validate_pointer_uninitialization();
    validate_maximum_item_count_reached();

    current_item_count += 1;
    pointer_integer_array_list = (int *)realloc(pointer_integer_array_list,
                                                sizeof(int) * (current_item_count));
    for (int current_index = current_item_count - 2;
         current_index >= 0; current_index -= 1)
    {
        *(pointer_integer_array_list + (current_index + 1)) = *(pointer_integer_array_list + current_index);
    }
    *pointer_integer_array_list = item;
}

void append_item_at_index(int item, int target_index)
{
    validate_pointer_uninitialization();
    validate_maximum_item_count_reached();
    validate_target_index(target_index);

    current_item_count += 1;
    pointer_integer_array_list = (int *)realloc(pointer_integer_array_list,
                                                sizeof(int) * (current_item_count));
    for (int current_index = current_item_count - 2;
         current_index >= target_index; current_index -= 1)
    {
        *(pointer_integer_array_list + (current_index + 1)) = *(pointer_integer_array_list + current_index);
    }
    *(pointer_integer_array_list + target_index) = item;
}

void append_item_at_the_last_index(int item)
{
    validate_pointer_uninitialization();
    validate_maximum_item_count_reached();

    current_item_count += 1;
    pointer_integer_array_list = (int *)realloc(pointer_integer_array_list,
                                                sizeof(int) * (current_item_count));
    *(pointer_integer_array_list + (current_item_count - 1)) = item;
}

void remove_item_at_the_first_index()
{
    validate_pointer_uninitialization();
    validate_item_count_reached_0();

    current_item_count -= 1;
    for (int current_index = 0; current_index < current_item_count;
         current_index += 1)
    {
        *(pointer_integer_array_list + current_index) = *(pointer_integer_array_list + current_index + 1);
    }
    *(pointer_integer_array_list + current_item_count) = (int)NULL;
    pointer_integer_array_list = (int *)realloc(pointer_integer_array_list,
                                                sizeof(int) * (current_item_count));
}

void remove_item_at_index(int target_index)
{
    validate_pointer_uninitialization();
    validate_item_count_reached_0();
    validate_target_index(target_index);

    current_item_count -= 1;
    *(pointer_integer_array_list + target_index) = (int)NULL;
    for (int current_index = target_index; current_index < current_item_count;
         current_index += 1)
    {
        *(pointer_integer_array_list + current_index) = *(pointer_integer_array_list + current_index + 1);
    }
    pointer_integer_array_list = (int *)realloc(pointer_integer_array_list,
                                                sizeof(int) * (current_item_count));
}

void remove_item_at_the_last_index()
{
    validate_pointer_uninitialization();
    validate_item_count_reached_0();

    current_item_count -= 1;
    *(pointer_integer_array_list + current_item_count) = (int)NULL;
    pointer_integer_array_list = (int *)realloc(pointer_integer_array_list,
                                                sizeof(int) * (current_item_count));
}

void reverse_order()
{
    validate_pointer_uninitialization();

    int middle_index = get_middle_index();
    for (int current_index = 0; current_index <= middle_index; current_index += 1)
    {
        int *pointer_rightwise_item = pointer_integer_array_list + (current_item_count - current_index - 1);
        int *pointer_leftwise_item = pointer_integer_array_list + current_index;
        int focused_item = *(pointer_rightwise_item);
        *(pointer_rightwise_item) = *(pointer_leftwise_item);
        *(pointer_leftwise_item) = focused_item;
    }
}

int find_index_of_item(int item)
{
    validate_pointer_uninitialization();

    for (int current_index = 0; current_index < current_item_count;
         current_index += 1)
    {
        if (*(pointer_integer_array_list + current_index) == item)
        {
            return current_index;
        }
    }
    return -1;
}

void print_properties()
{
    validate_pointer_uninitialization();

    printf("current_item_count: %d\n", current_item_count);
    printf("maximum_item_count: %d\n", maximum_item_count);
    printf("is_memory_free: %d\n", is_memory_free);
    printf("is_initialized: %d\n", is_initialized);
    printf("Items: [");
    for (int current_index = 0; current_index < current_item_count;
         current_index += 1)
    {
        printf("%d", *(pointer_integer_array_list + current_index));
        if (current_index < current_item_count - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}