# Lecture 2
Our goal today is to become more familiar with git and GitHub. We already started using it last week (these lecture notes are stored on GitHub) but we did so without talking about what it is and why we use it. 

## git vs GitHub
First, there can be some confusion (because of almost identical names) about the tools we're using here. One tool is called git. It's a program running on your computer that is used to track changes to code and other files, especially text files. For instance, you would use git to remove one line of code and substitute it with another and "commit" this change once you were happy with it. GitHub, on the other hand, is a mostly online application where we can store our projects (called repositories or repos for short) that we track using git. Think of it like Dropbox, Google Drive, or OneDrive, but with better "version control." (We'll come back to that term later).

Since the professionals at GitHub are better at describing it than I am, let's turn to their curated resources. Here is a link to their "What is GitHub" video: https://www.youtube.com/watch?v=w3jLJU7DT5E. 

## Motivation
We will begin to create repositories for our class projects, following the best practices that they describe. This class is not designed to teach you all of git/GitHub's amazing functionality, but it is designed to help you get comfortable with some of the basics. 

## Guided Activity
Complete the [Introduction to GitHub course](https://lab.github.com/githubtraining/introduction-to-github). 

## From now on...
All code and other design files for this class must be tracked using git and uploaded to GitHub. This will allow for real-time collaboration across your teams, file sharing for open science/engineering, and the creation and curation of a portfolio that you can show potential employers or graduate advisors. Not all companies and grad programs utilize git/GitHub, but many will be very impressed if you bring this skillset.

## On your own
Form teams of two. Work together on all of the following steps, but have a different person lead each step using their own GitHub account.
- Person 1: Create a GitHub repository for your LED blinking code from last class. Commit your code and push it to the main branch of the repository.
- Person 2: Fork the repository created by Person 1. Create a branch called "SOS." Begin working on (i.e., "check out" that branch). Change the code to make the LED blink out an "SOS" signal. Look up Morse code if needed. (Hint: there may be example code out there on the web already; you would likely have to modify it for your microcontroller, but may not have to write all of it yourself). Commit changes to your new branch as appropriate. Once the SOS code is fully functional, create a Pull Request (PR) on the original repository. 
- Person 1: Review the PR and merge it into your main repository's main branch if appropriate.