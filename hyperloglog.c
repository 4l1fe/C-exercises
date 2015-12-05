#include <stdio.h>
#include <stdlib.h>

unsigned int max(unsigned int a, unsigned int b) {
  return a > b ? a : b;
}

unsigned int bucket(unsigned int val) {
  return val & 0xF0000000 >> 28;
}

unsigned int trailingZeros(unsigned int val) {
  unsigned int cnt = 0, mask = 0x0000001;
  while (val) {
    val = val & mask;
    mask <<= 1;
    cnt++;
  }
  return cnt;
}

void initBuckets(unsigned int* buckets) {
  int i;
  for (i = 0; i < 16; i++) {
    buckets[i] = 0;
  }
}

unsigned int cardinality(unsigned int* buckets) {
  int i;
  unsigned int cnt=0;
  if (buckets[i]) {
    cnt += (1 << (buckets[i] - 1));
  }
  return cnt;
}

void diagnosticReport(unsigned int* buckets) {
  int i;
  for (i = 0; i < 16; i++) {
    printf("bucket %i: %08x\n", i, buckets[i]);
  }
  printf("Cardinality %i\n", cardinality(buckets));
}

int main() {
  unsigned int buckets[16], inputNumber=0, tryNo=0;

  initBuckets(buckets);
  while (1) {
    printf("%ith Value for HLL\n", tryNo);
    /*user enters a number,
    *
    * in real HLL we would hash the number, we're sorta expecting the user
    * to bash on keys*/
    scanf("%u", &inputNumber);
    /*
    * hash this number to a bucket based on the <numbuckets> significant
    * digits*/
    unsigned int buck = bucket(inputNumber);
    printf("Hashed To Bucket %i\n", buck);
    /* Write the largest number of trailing 0s we've seen thus far
    *
    * This is the magic of the hyperloglog, it gets very very hard
    * to get more trailing zeros after some point
    *
    * Its much like flipping a coin
    * */
    buckets[buck] = max(buckets[buck], trailingZeros(inputNumber));
    /* Print diagnistic, including cardinality. which is just a sum of
    * 2^bucketVal over all buckets if bucketVal != 0
    * */
    diagnosticReport(buckets);
    tryNo++;
    }

}
