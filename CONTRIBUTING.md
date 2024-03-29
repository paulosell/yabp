# Contributing to YABP Repository

Thank you for considering contributing to this repository! Your contributions help make this resource more valuable for others. Before you start, please take a moment to review these guidelines.

## How to Contribute

1. **Fork the Repository:** Click the "Fork" button at the top-right corner of this repository to create your copy.

2. **Clone Your Fork:** Clone your forked repository to your local machine using `git clone`:
```shel
git clone https://github.com/your-username/yabp.git
```

3. **Create a Branch:** Create a new branch for your work. Use a descriptive branch name that reflects the nature of your contribution:
```shell
cd yabp
git checkout -b feature/your-feature-name
```

4. **Make Changes:** Make your desired changes to the codebase, add new algorithms, improve existing implementations, or fix issues.

5. **Run Cppcheck:** Before creating a pull request, please ensure that you run [Cppcheck](https://cppcheck.sourceforge.io/) on your code using the following command and fix any errors or warnings returned:
```shell
cppcheck --enable=all --inconclusive --std=c++11 --language=c++ --suppress=missingIncludeSystem path/to/src
```

6. **Commit Your Changes:** Commit your changes with a clear and concise commit message:
```shell
git commit -m "Add feature/fix: brief description of your changes"
```

7. **Push to Your Fork:** Push your changes to your forked repository:
```shell
git push origin feature/your-feature-name
```
8. **Create a Pull Request (PR):** Go to the original repository on GitHub and click the "New Pull Request" button. Provide a clear title and description for your PR, explaining what it adds or fixes.

9. **Review and Discussion:** Participate in the discussion related to your pull request. Be ready to address feedback and make changes if necessary.

10. **Merge:** Once your contribution is approved, it will be merged into the main repository. Congratulations on your contribution!

## Code Style and Guidelines

- Please maintain a consistent coding style within your C++ code contributions.
- Ensure your code is well-documented, with comments explaining its purpose and usage.
- Adhere to best practices and follow the guidelines specifics
- Test your code to verify that it works as expected.

## Reporting Issues

If you encounter a bug, have a suggestion, or want to discuss improvements, please open an issue on the repository. Provide detailed information about the problem or suggestion to help us understand and address it.

Thank you for your contributions and for helping others learn about algorithms! :smile: 




