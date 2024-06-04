
class Heap_Value_Proxy
{
public:
    Heap_Value_Proxy(void *pointer, int byte_size)
    {
        Heap_Value_Proxy::allocate(pointer, byte_size);
    }

    void *get_pointer()
    {
        return Heap_Value_Proxy::pointer;
    }

    int get_byte_size()
    {
        return Heap_Value_Proxy::byte_size;
    }

    int get_is_allocated()
    {
        return Heap_Value_Proxy::is_allocated;
    }

    void allocate(void *pointer, int byte_size)
    {
        Heap_Value_Proxy::handle_heap_memory_allocation(byte_size);
        Heap_Value_Proxy::pointer = pointer;
        Heap_Value_Proxy::byte_size = byte_size;
    }

    void reallocate(int byte_size)
    {
        Heap_Value_Proxy::handle_heap_memory_reallocation(Heap_Value_Proxy::pointer, byte_size);
        Heap_Value_Proxy::byte_size = byte_size;
    }

    void deallocate()
    {
        if (!Heap_Value_Proxy::is_allocated)
        {
            Heap_Value_Proxy::pointer = NULL;
            free(Heap_Value_Proxy::pointer);
            Heap_Value_Proxy::is_allocated = 0;
            Heap_Value_Proxy::byte_size = 0;
        }
    }

private:
    void *pointer;
    int byte_size = 0;
    int is_allocated = 0;
    
    void handle_heap_memory_allocation(int byte_size)
    {
        if (!Heap_Value_Proxy::is_allocated)
        {
            Heap_Value_Proxy::pointer = (void *)malloc(byte_size);
            Heap_Value_Proxy::is_allocated = 1;
        }
    }

    void handle_heap_memory_reallocation(void *pointer, int byte_size)
    {
        if (!Heap_Value_Proxy::is_allocated)
        {
            Heap_Value_Proxy::pointer = (void *)realloc(pointer, byte_size);
            Heap_Value_Proxy::is_allocated = 1;
        }
    }
};

// REFERENCES
// int numbers[5] = {1, 2, 3, 4, 5};
// char string[6] = "Hello";
// Heap_Value_Proxy HeapValueA(numbers, 20);

// printf("- Start:\n");
// for (int i = 0; i < 5; i += 1)
// {
//     printf("--- %d\n", *(((int *)HeapValueA.getValue()) + i));
// }
// printf("- End:\n");

// HeapValueA.deallocate();
// HeapValueA.allocate(string, 6);

// printf("- Start:\n");
// for (int i = 0; i < 5; i += 1)
// {
//     printf("--- %c\n", *(((char *)HeapValueA.getValue()) + i));
// }
// printf("- End:\n");
