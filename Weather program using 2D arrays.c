#include <stdio.h>

#include <stdlib.h>

void multiplyMatrices() {
  int matrixRows1 = 0, matrixColumns1 = 0, matrixRows2 = 0, matrixColumns2 = 0;
  int isMultiply = 0, userChoice = 0;
  do {
    // Asking the user to enter the size of both of the matrices, rows and
    // column wise.
    printf("Please input the size of the first matrix.\n");
    printf("rows: ");
    scanf("%d", & matrixRows1);
    printf("Columns: ");
    scanf("%d", & matrixColumns1);
    printf("\nPlease input the size of the second matrix.\n");
    printf("rows: ");
    scanf("%d", & matrixRows2);
    printf("\ncolumns: ");
    scanf("%d", & matrixColumns2);

    // Making sure that the number of columns of the first matrix is equal to
    // the number of rows in the second matrix - in order to multiply them.

    if (matrixColumns1 != matrixRows2) {
      printf(
        "\nIn order to multiply matrices, the number of columns in the first "
        "matrix has to equal the number of rows of the second.");
      printf(
        "Please retry with different matrices and make sure of the "
        "condition.\n");
      isMultiply = 0;
    } else {
      isMultiply = 1;
    }
  } while (isMultiply == 0);

  float matrix1[matrixRows1][matrixColumns1]; // Initializing the first matrix.
  float matrix2[matrixRows2][matrixColumns2]; // Initializing the second
  // matrix.

  do {
    // Creating a loop for the user to assign the matrix values.
    printf("Enter the values for the first Matrix:\n");
    for (int i = 0; i < matrixRows1; i++) {
      for (int j = 0; j < matrixColumns1; j++) {
        printf("Enter the value for element at position (%d, %d): ", i + 1,
          j + 1);
        scanf("%f", & matrix1[i][j]);
      }
    }
    printf("Enter the values for the second Matrix:\n");
    for (int i = 0; i < matrixRows2; i++) {
      for (int j = 0; j < matrixColumns2; j++) {
        printf("Enter the value for element at position (%d, %d): ", i + 1,
          j + 1);
        scanf("%f", & matrix2[i][j]);
      }
    }

    // Prompting the user with the matrix values they entered and checking if
    // they are correct or not.
    printf("The First matrix you have Entered is: \n");
    for (int i = 0; i < matrixRows1; i++) {
      for (int j = 0; j < matrixColumns1; j++) {
        printf("| %8.2f ",
          matrix1[i][j]); // Properly spaced columns with borders
      }
      printf("|\n");
    }
    printf("The Second matrix you have Entered is:\n");
    for (int i = 0; i < matrixRows2; i++) {
      for (int j = 0; j < matrixColumns2; j++) {
        printf("| %8.2f ",
          matrix2[i][j]); // Properly spaced columns with borders
      }
      printf("|\n");
    }

    // Asking the user if the matrix entered values are correct or not.
    printf("Is this correct? 1 for Yes, 0 for No: ");
    scanf("%d", & userChoice);
    do {
      if (userChoice != 1 && userChoice != 0) {
        printf("Please enter a correct value.\n");
        userChoice = 0;
      } else {
        break;
      }
    } while (userChoice != 0 && userChoice != 1);
  } while (userChoice != 1);

  // Create a matrix to store the result
  float resultMatrix[matrixRows1][matrixColumns2];

  // Initialize resultMatrix elements to 0
  for (int i = 0; i < matrixRows1; i++) {
    for (int j = 0; j < matrixColumns2; j++) {
      resultMatrix[i][j] = 0;
    }
  }

  // Making the a loop for multiplying the matrices.
  for (int i = 0; i < matrixRows1; i++) {
    for (int j = 0; j < matrixColumns2; j++) {
      for (int k = 0; k < matrixColumns1; k++) {
        resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  // Display the result
  printf("Result of matrix multiplication:\n");
  for (int i = 0; i < matrixRows1; i++) {
    for (int j = 0; j < matrixColumns2; j++) {
      printf("| %8.2f ", resultMatrix[i][j]);
    }
    printf("|\n");
  }
}

void transposeMatrix() {
  int matrixRows = 0, matrixColumns = 0, userChoice = 0;
  // Asking the user to enter the size of the matrix, rows and column wise.
  printf("Please input the size of the matrix.\n");
  printf("rows: \n");
  scanf("%d", & matrixRows);
  printf("Columns: \n");
  scanf("%d", & matrixColumns);
  float matrix1[matrixRows][matrixColumns];

  do {
    // Creating a loop for the user to assign the matrix values.
    for (int i = 0; i < matrixRows; i++) {
      for (int j = 0; j < matrixColumns; j++) {
        printf("Enter the value for element at position (%d, %d): ", i + 1,
          j + 1);
        scanf("%f", & matrix1[i][j]);
      }
    }

    // Prompting the user with the matrix values they entered and checking if
    // they are correct or not.
    printf("The matrix you have Entered is: \n");
    for (int i = 0; i < matrixRows; i++) {
      for (int j = 0; j < matrixColumns; j++) {
        printf("| %8.2f ",
          matrix1[i][j]); // Properly spaced columns with borders
      }
      printf("|\n");
    }

    // Asking the user if the matrix entered values are correct or not.
    printf("Is this correct? 1 for Yes, 0 for No: ");
    scanf("%d", & userChoice);
    do {
      if (userChoice != 1 && userChoice != 0) {
        printf("Please enter a correct value.\n");
        userChoice = 0;
      } else {
        break;
      }
    } while (userChoice != 0 && userChoice != 1);
  } while (userChoice != 1);

  float transposedMatrix[matrixRows][matrixColumns];

  for (int i = 0; i < matrixRows; i++) {
    for (int j = 0; j < matrixColumns; j++) {
      transposedMatrix[j][i] = matrix1[i][j];
    }
  }
  // Prompting the user with the Transposed Matrix.
  printf("The Transposed matrix is: \n");
  for (int i = 0; i < matrixRows; i++) {
    for (int j = 0; j < matrixColumns; j++) {
      printf("| %8.2f ",
        transposedMatrix[i][j]); // Properly spaced columns with borders
    }
    printf("|\n");
  }
}

int main() {
  int rerun = 0, userChoice = 0;
  do {
    printf(
      "Choose what you want to do:\n1) Transpose Matrix.\n2) Multiply "
      "Matrices.\n");
    scanf("%d", & userChoice);

    switch (userChoice) {
    case 1:
      transposeMatrix();
      break;
    case 2:
      multiplyMatrices();
      break;
    default:
      printf("Choose a correct value and try again please.");
      break;
    }

    printf(
      "Do you want to rerun the program?\nEnter 1 to rerun or 0 to Exit.\n");
    scanf("%d", & rerun);

    // Creating a loop to make sure the user entered a correct value between 0
    // and 1 to rerun or exit the program.
    do {
      if (rerun != 1 && rerun != 0) {
        printf("Please enter a correct value.\n");
        rerun = 0;
      } else {
        break;
      }
    } while (rerun != 0 && rerun != 1);

  } while (rerun == 1);
  return 0;
}
