#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sam_strcat.h" // Change this to your header file name

#define LEN 128

void testStrings(char *a, char *b) { 
  if (strlen(a) != strlen(b)) {
    printf("FAILED: %s != %s\n", a, b);
    exit(1);
  }
  for(; *a == *b && *a != '\0'; a++, b++);
  if(*a == '\0' && *b == '\0') {
    printf("SUCCESS\n");
  }
  else {
    printf("FAILED: %s != %s\n", a, b);
    exit(1);
  }
}

void randomString(char *t, int max_len) {
  int len = rand()%max_len;
  char c;
  for(int i = 0; i < len; i++, t++) {
    // Create a random ascii character
    // ascii letters start from 97 and end at 122, sequentially
    c = rand()%26 + 97; 
    *t = c;
  }
  *t = '\0';
}

int main() {
  char s[LEN]; 
  char t[LEN];
  char check[LEN]; 

  srand(time(NULL));

  // Test "sam" + " mansfield" = "sam mansfield" 
  strcpy(s, "sam");
  strcpy(t, " mansfield");
  strcpy(check, "sam mansfield");
  my_strcat(s, t);
  testStrings(s, check);
  
  // Test "b" + "anana" = "banana"
  strcpy(s, "b");
  strcpy(t, "anana");
  strcpy(check, "banana");
  my_strcat(s, t);
  testStrings(s, check);

  // Test "" + "test" = "test"
  strcpy(s, "");
  strcpy(t, "test");
  strcpy(check, "test");
  my_strcat(s, t);
  testStrings(s, check);
  
  // Test "test" + "" = "test"
  strcpy(s, "test");
  strcpy(t, "");
  strcpy(check, "test");
  my_strcat(s, t);
  testStrings(s, check);
 
  // Random testing
  for(int i = 0; i < 1000; i++) { 
    randomString(s, LEN);
    strcpy(check, s);
    randomString(t, LEN - strlen(s));
    my_strcat(s, t);
    strcat(check, t);
    testStrings(check, s);
  }


  return 0;
}
