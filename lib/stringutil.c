#include "../include/stringutil.h"


int string_cmp(char *str1, char *str2) {
    int i = 0;
    while(str1[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] > str2[i] ? 1 : -1;
        }
        else i++;
    }
    return 0;     
}


int string_length(char *str) {
    int length = 0;
    while(str[length] != '\0') {
        length++;
    }
    return length;
}


void string_copy(char *dest, char *src) {
    int index = 0;
    
    while((dest[index] = src[index]) != '\0') {
        index++;
    }

    dest[index] = '\0';

}


char* string_concat(char *str1, char *str2) {
    int length1 = string_length(str1);
    int length2 = string_length(str2);
    int n_length = length1 + length2;
    char *concat = (char*) calloc(n_length, sizeof(char));

    int i = 0;
    
    while((concat[i] = str1[i]) != '\0') {
        i++;
    }
    
    i = 0;
    
    while((concat[length1 + i] = str2[i]) != '\0') {
        i++;
    }

    concat[n_length] = '\0';

    return concat;
}


char* string_init_cut(char *str, int index) {
    int length = string_length(str);
    char* new_str = substring_at_be(str, index, length - 1);
    return new_str;
}


char* string_end_cut(char *src, int index) {
     char* new_str = substring_at_be(src, 0, index);
     new_str[index] = '\0';
     return new_str;
}


char* substring_at_be(char *str, int begin, int end) {
    int length = end - begin + 1;
    char *sub = (char*) calloc(length, sizeof(char));

    int i = 0;
    while(i < length) {
        sub[i] = str[i+begin];
        i++;
    }
    sub[i] = '\0';
    
    return sub;
}


char* string_nconcat(char *dest, char *src, int n) {
    int length = string_length(dest) + n;
    char *new_str = (char *) calloc(length, sizeof(char));
    int i = 0;

    while((new_str[i] = dest[i]) != '\0') {
        i++;
    }
    int j = i;
    for(i = 0; i < n; i++) {
        new_str[j+i] = src[i];
    }
    new_str[j+i] = '\0';

    return new_str;
}


void string_ncopy(char *dest, char *src, int n) {
    int i;

    for(i = 0; i < n; i++) {
        dest[i] = src[i];
    }

    dest[n] = '\0';    
}


int string_ncmp(char *str1, char *str2, int n) {
     int i = 0;
    while(str1[i] != '\0' && i < n) {
        if (str1[i] != str2[i]) {
            return str1[i] > str2[i] ? 1 : -1;
        }
        else i++;
    }
    return 0;  

}


void string_trim(char *src) {
    int length = string_length(src);
    int i = 0;
    
    while(src[i] != '\0' && (src[i] == ' ' || src[i] == '\t' || src[i] == '\n')) {
        i++;
    }
    string_init_cut(src, (i-1));
    length = string_length(src);
    i = length -1;
    while((src[i] == ' ' || src[i] == '\t' || src[i] == '\n')) {
        i--;
    }
    src[i + 1] = '\0';
}


char* append_char_to_string(char character, char *string) {
    char *new_str = (char*) calloc(1, sizeof(char));
    new_str[0] = character;
    return string_concat(string, new_str);
}


int string_begins_with(char* prefix, char* str) {
    int length = string_length(prefix);
    int count;

    for(count = 0; count < length; count++) {
        if(prefix[count] != str[count]) return 0;
    }
    return 1;
}


int string_contains_str(char* str, char* sequence) {
	int size = string_length(str);
	int seq_size = string_length(sequence);
	
	if(seq_size > size) return 0;

	int i,j;
	for(i = 0; i < size; i++) {
		j = 0;
		if(str[i] == sequence[j]) {
			while(j < seq_size &&  str[i] == sequence[j]) {
				j++;
				i++;
			}
			if(j == seq_size) return 1;
		}
	}
	return 0;
}


int string_contains_char(char* str, char c) {
    int i = 0, length = string_length(str);

    while(i < length) {
        if(str[i] == c) return 1;
        i++;
    }
    return 0;
    
}


char* string_cut_first_occurrence(char* str, char* sequence) {
    if(string_contains_str(str, sequence) < 0) return NULL;
    int i,j;
    int size = string_length(str);
	int seq_size = string_length(sequence);
    int begin_index = 0, end_index = 0;
    for(i = 0; i < size; i++) {
		j = 0;
		if(str[i] == sequence[j]) {
            begin_index = i;
			while(j < seq_size &&  str[i] == sequence[j]) {
				j++;
				i++;
			}
            end_index = i;
            if(j == seq_size - 1) {
                break;
            }
			
		}
	}
    char* first = (char*) calloc(begin_index+1, sizeof(char));
    string_ncopy(first, str, begin_index);

    char* second = (char*) calloc(string_length(str) - end_index, sizeof(char));
    second = substring_at_be(str, end_index, string_length(str) - 1);

    char* result = (char*) calloc(string_length(first) + string_length(second), sizeof(char));
    result = string_concat(first, second);
    free(first);
    free(second);
    return result; 
}


char* string_first_sequence_occur(char* str, char* sequence) {
    int size = string_length(str);
	int seq_size = string_length(sequence);
	
	if(seq_size > size) return NULL;

	int i,j, begin;
    char* p; 
	for(i = 0; i < size; i++) {
		j = 0;
        begin = i;
		if(str[i] == sequence[j]) {
            while(j < seq_size &&  str[i] == sequence[j]) {
				j++;
				i++;
			}
            if(j == seq_size) {
                p = &str[begin];
                return p;
            }
		}
	}
    return NULL;
}


char* string_last_sequence_occur(char* str, char* sequence) {
    if(string_contains_str(str, sequence) < 1) return NULL;
    int size = string_length(str);
	int seq_size = string_length(sequence);
	
	if(seq_size > size) return NULL;

	int i,j, begin;
    char* p = NULL; 
	for(i = 0; i < size; i++) {
		j = 0;
        begin = i;
		if(str[i] == sequence[j]) {
            while(j < seq_size &&  str[i] == sequence[j]) {
				j++;
				i++;
			}
            if(j == seq_size) {
                p = &str[begin];
            }
		}
	}
	return p;
}


char* get_file_content(char* file_path) {
    FILE* file = fopen(file_path, "r");
    char c;
    int size = 1;
    char* file_content = (char*) calloc(size, sizeof(char));
    if(file == NULL) {
        perror("ERROR: ");
        return NULL;
    }
    while((c = fgetc(file)) != EOF) {
        file_content[size-1] = c;
        size++;
        file_content = realloc(file_content, size);
    }
    
    file_content[size-1] = EOF;

    return file_content;
}


char** string_split_index(char* str, int index) {
    int length = string_length(str);
    char* begin = (char*) calloc(index, sizeof(char));
    string_ncopy(begin, str, index);
    char* end = string_init_cut(str, index + 1);

    char** split = (char**) calloc(2, sizeof(char*));
    split[0] = begin;
    split[1] = end;

    return split;
}


int* string_char_occurrences(char* str, char c) {
    int* occur = (int*) calloc(1, sizeof(int));
    int length = string_length(str), i, j = 0;

    for(i = 0; i <  length; i++) {
        if(str[i] == c) {
            if(j >  0) occur = (int*) realloc(occur, j + 1);
            occur[j] = i;
            j++;     
        }
    }

    return occur;
}


int string_number_occurrences(char* str, char c) {
    int length = string_length(str);
    int i, count = 0;

    for(i = 0; i < length; i++) {
        if(str[i] == c) count++; 
    }

    return count;
}


char** string_split_char(char* str, char c) {
    int i, j = 0, begin = 0, end;
    int size_split = string_number_occurrences(str,c) + 1;
    char** split = (char**) calloc(size_split, sizeof(char*));
    char* sub;
    for(i = 0; i < size_split; i++) {
        
        while(str[j] != c) {
            j++;
        }
    
        end = j;
        if(begin == 0) sub = substring_at_be(str, begin, end - 1);
        else sub = substring_at_be(str, begin + 1, end - 1);
        begin = end;
        split[i] = sub;
        j++;
    }
    
    return split;
}


char** get_file_content_by_lines(char* file_path) {
    char* file_content = get_file_content(file_path);
    int str_len = string_length(file_content), i = 0, begin = 0, end = 0;
    int num_lines = string_number_occurrences(file_content, '\n') + 1;
    char** lines = (char**) calloc(num_lines, sizeof(char*));
    char* line;
    int line_number = 0;

    while(i < str_len && file_content[i] != EOF) {
        if(file_content[i] == '\n') {
            end = i;
            line = substring_at_be(file_content, begin, end - 1);
            begin = end + 1;
            lines[line_number] = line;
            line_number++;
        }
        
        i++;
    }
    
    return lines;
}


void print_bidimensional_char_array(char** bidimensional_array, int columns) {
    int i;
    
    for(i = 0; i < columns; i++) {
        printf("%s\n", bidimensional_array[i]);
    }
}


int number_of_lines(char* str) {
    int length = string_length(str);
    if(length == 0) return 0;
    int i = 0, number = 0; 
    while(i < length) {
        if(str[i] == '\n') {
            number++;
        }
        i++; 
    }

    return number;
    
}


int number_of_file_lines(char* file_path) {
    char* file_content = get_file_content(file_path);
    return number_of_lines(file_content);
}



void replace_first_char(char* str[], char c, char replacement) {
    int length  = string_length(*str);
    char* tmp = (char*) calloc(length, sizeof(char));
    if(string_contains_char(*str, c) ==  1) {
        int i = 0;
        while(i < length) {
            if((*str)[i] == c) {
                tmp[i] = replacement;
            }
            else {
                tmp[i] = (*str)[i];
            }
            i++;
        }
        *str = tmp;
    }
}