#include <iostream>
#include <stdio.h>

using namespace std;

int votes[3] = { 0, 0, 0 };

int countvote(int vote) {
  votes[vote]++;
  return vote;
}

void votemachine() {
  char votenumber[20];
  int votenum = 0;
  cout << "How many millions of votes? ";
  scanf("%[0-9.]", votenumber);
  int i = -1;
  while (votenumber[++i] != '\0') {
    if (votenumber[i] >= '0' && votenumber[i] <= '9')
      { votenum = (votenum * 10) + (votenumber[i] - '0'); }
  }
  cout << votenum << " millions of votes.\n";
  int j = -1;
  while (++j < (votenum * 1000000)) {
    int randomvote = 1;
    if (j < atof(votenumber) * 1000000.0) // { continue; }
      { randomvote = ((j << 4 / 6 >> 4) % 2) + 1; } // 1 or 2
    // todo: give random independent votes
    countvote(randomvote); // j << 4 + 6 >> 4);
  }
  cout << "BLUE VOTES: " << votes[1] << "\n";
  cout << "RED VOTES: " << votes[2] << "\n";
  if (votes[1] > votes[2]) {
    cout << "BLUE WINS!\n";
  } else {
    cout << "RED WINS!\n";
  }
}

int main(int argc, char **argv) {
  votemachine();
}
