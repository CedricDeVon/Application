
void rna_reverse_complement()
{
    /*
    -- RNA Reverse Complement
    Create a function that finds the reverse complement of a ribonucleic acid (RNA) strand.
    The RNA will be represented as a string containing only the characters "A", "C", "G" and "U".
    Since RNA can only (canonically) allow pairings of A/U and G/C, the complement of an RNA would be as follows:

    Original	Complement
    "AAA"	"UUU"
    "UUU"	"AAA"
    "GGG"	"CCC"
    "CCC"	"GGG"
    */

    char rna_sequence[128] = "";
    printf("Enter RNA Sequence: \n");
    scanf("%s", &rna_sequence);
    printf("Original RNA Sequence: %s \n", rna_sequence);

    int rna_sequence_length = strlen(rna_sequence);
    for (int index = 0; index < rna_sequence_length; index++)
    {
        char rna_character = toupper(rna_sequence[index]);
        switch (rna_character)
        {
        case 'A':
            rna_sequence[index] = 'U';
            break;

        case 'U':
            rna_sequence[index] = 'A';
            break;

        case 'G':
            rna_sequence[index] = 'C';
            break;

        case 'C':
            rna_sequence[index] = 'G';
            break;
        }
    }

    printf("Reversed RNA Sequence: %s \n", rna_sequence);
}
