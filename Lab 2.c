#include <stdio.h>

int main()
{
    // We're evaluating exactly 4 suppliers for this lab
    const int NUM_SUPPLIERS = 4;

    // supplierName[4][50]: an array of 4 strings, each string can hold up to 49 characters + terminator
    // This is pre-filled with the exact suppliers from the lecture notes' worked example
    char supplierName[4][50] = {"Supplier A", "Supplier B", "Supplier C", "Supplier D"};

    // Each array below lines up by position with supplierName —
    // price[0] belongs to Supplier A, price[1] to Supplier B, and so on
    float price[4] = {95000, 88000, 82000, 91000};
    int registered[4] = {1, 1, 0, 1};          // 1 = Yes, 0 = No
    int documentsComplete[4] = {1, 1, 1, 0};   // 1 = Yes, 0 = No

    float budget = 100000;   // the maximum price allowed to qualify

    int qualified[4];              // will store 1 (qualified) or 0 (disqualified) for each supplier
    int preferredIndex = -1;       // will hold the array position of the cheapest qualified supplier
                                    // -1 means "none found yet"
    float lowestQualifiedPrice = 0; // tracks the lowest price seen so far among qualified suppliers

    printf("--- Tender Evaluation Report ---\n");

    // Loop through all 4 suppliers one at a time
    for (int i = 0; i < NUM_SUPPLIERS; i++)
    {
        printf("\nSupplier: %s\n", supplierName[i]);
        printf("Price: %.2f\n", price[i]);

        // Disqualification rule: not registered, OR missing documents, OR price too high
        if (registered[i] == 0 || documentsComplete[i] == 0 || price[i] > budget)
        {
            qualified[i] = 0;
            printf("Status: Disqualified\n");
        }
        else
        {
            // This supplier passed all checks
            qualified[i] = 1;
            printf("Status: Qualified\n");

            // Check if this is the cheapest QUALIFIED supplier found so far
            // preferredIndex == -1 means "no qualified supplier found yet, so this one wins by default"
            // price[i] < lowestQualifiedPrice means "this one is even cheaper than our current best"
            if (preferredIndex == -1 || price[i] < lowestQualifiedPrice)
            {
                preferredIndex = i;              // This supplier's position
                lowestQualifiedPrice = price[i]; // This price as the new lowest
            }
        }
    }

    // After checking all 4 suppliers, announce the winner
    printf("\n--- Result ---\n");
    if (preferredIndex != -1)
    {
        // preferredIndex tells us WHICH supplier won, so we look up their name using it
        printf("Preferred Supplier: %s (Price: %.2f)\n",
               supplierName[preferredIndex], lowestQualifiedPrice);
    }
    else
    {
        // This only happens if every single supplier was disqualified
        printf("No qualified suppliers found.\n");
    }

    return 0;
}