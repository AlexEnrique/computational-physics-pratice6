double h(int i) {
  // retorna h_i
  // N¨: i \in {1, 5}
  // C: i \in {2, 3, 4, 6}
  switch (i) {
    case 1-1:
      return 1.5;
    case 5-1:
      return 1.5;
    default:
      return -0.0;
  }
}

double k(int i) {
  // retorna k_{i, i+1}
  // k_{N¨=C}: i == 1, 5
  // K_{C-C}: i == 2
  // k_{C=C}: i == 3
  // k_{N¨-C}: i == 4
  switch (i) {
    case 1-1:
      return 1.0;
    case 5-1:
      return 1.0;
    case 2-1:
      return 0.9;
    case 3-1:
      return 1.1;
    case 4-1:
      return 1.0;
  }
}

double num(int j) {
  switch (j) {
    case 1-1:
      return 2.0;
    case 3-1:
      return 2.0;
    case 5-1:
      return 2.0;
    default:
      return 0.0;
  }
}
