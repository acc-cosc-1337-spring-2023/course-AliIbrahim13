//add include statements

//add function code here
#include "func.h"

double get_gc_content(const std::string& dna) {
    int count = 0;
    for(char c : dna) {
        if(c == 'C' || c == 'G') {
            count++;
        }
    }
    return (double)count / dna.size();
}

std::string get_reverse_string(std::string dna) {
    for(int i = 0, j = dna.size() - 1; i < j; i++, j--) {
        char temp = dna[i];
        dna[i] = dna[j];
        dna[j] = temp;
    }
    return dna;
}

std::string get_dna_complement(std::string dna) {
    std::string complement = "";
    for(char& c : dna) {
        switch(c) {
            case 'A':
                complement += 'T';
                break;
            case 'T':
                complement += 'A';
                break;
            case 'C':
                complement += 'G';
                break;
            case 'G':
                complement += 'C';
                break;
        }
    }
    return get_reverse_string(complement);
}
