# Lecture 2
Our goal today is to become more familiar with git and GitHub. We already started using it last week (these lecture notes are stored on GitHub) but we did so without talking about what it is and why we use it. 

## git vs GitHub
First, there can be some confusion (because of almost identical names) about the tools we're using here. One tool is called git. It's a program running on your computer that is used to track changes to code and other files, especially text files (code is just basic text that follows specific syntax; it doesn't become instructions for a microcontroller or computer until it is compiled and/or executed). For instance, you would use git to remove one line of code and substitute it with another and "commit" this change once you were happy with it. This is useful when you want to save your progress at specific checkpoints, especially when collaborating. This feature allows you to backtrack to previous versions of code without always doing "save as" and renaming your code!

GitHub, on the other hand, is a mostly online application where we can store our projects (called repositories or repos for short) that we track using git. Think of it like Dropbox, Google Drive, or OneDrive, but with better "version control." (We'll come back to that term later). GitHub also allows us to make our repositories public in a very straightforward way, which is a wonderful way to contribute to open science and engineering.

Since the professionals at GitHub are better at describing it than I am, let's turn to their curated resources to learn more about GitHub. Here is a link to their "What is GitHub" video: https://www.youtube.com/watch?v=pBy1zgt0XPc. 

## READMEs and Markdown
Note that the file you are currently reading is a rendered version of the readme.md file in this folder (you could also click on the readme.md file to navigate directly to it, just like you could click on any other file). GitHub always renders the readme.md file of the folder you are looking at in the main browser window. Readmes are therefore very helpful tools to provide information in an "in your face" way that doesn’t require people to track down the info they might need to learn about the folder that they are in.

Also, .md refers to a “markdown” file. Markdown is a powerful and effective website language that is WAY simpler to learn than .html (Hyper-Text Markup Language; note that .md's "markdown" is meant to be the simpler version of .html's "markup"). Learn more about markdown here: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax. 

## Motivation
We will begin to create repositories for our class projects, following the best practices that they describe. This class is not designed to teach you all of git/GitHub's amazing functionality, but it is designed to help you get comfortable with some of the basics. 

## Guided Activity
1. (Required) Create a GitHub account if you don't already have one
2. (Required) Complete the [Introduction to GitHub course](https://github.com/skills/introduction-to-github)
3. (Required) Copy the hyperlink to the PROFILE.md file that you created through the exercise in Step 2. Paste it in the Canvas Discussion that is marked as an assignment due next week.
4. (Optional) In Step 2, you created a PROFILE.md file in a repository named skills-introduction-to-github. You now have the skills to make a much more visible profile for your GitHub repository. Create a repository called `your-username` where of course you change `your-username` with your actual new GitHub username. Then, create a README.md file and make your profile there. Point employers to this as an electronic resume of your coding skills, especially after filling out your profile with additional repositories containing (preferably code-based) projects you've worked on before.

Here is my profile as an example: https://github.com/SUPScientist. 

## From now on...
**All code and other design files for this class must be tracked using git and uploaded to GitHub**. This will allow for real-time collaboration across your teams, file sharing for open science/engineering, and the creation and curation of a portfolio that you can show potential employers or graduate advisors. Not all companies and grad programs utilize git/GitHub, but many will be very impressed if you bring this skillset.

## For Next Class
**This does not have to be completed prior to next class!!!**
Form teams of two. Work together on all of the following steps, but have a different person lead each step using their own GitHub account.
- Person 1: Create a GitHub repository for your LED blinking code from last class. Commit your code and push it to the main branch of the repository.
- Person 2: Fork the repository created by Person 1. Create a branch called "SOS." Begin working on (i.e., "check out" that branch). Change the code to make the LED blink out an "SOS" signal. Look up Morse code if needed. (Hint: there may be example code out there on the web already; you would likely have to modify it for your microcontroller, but may not have to write all of it yourself). Commit changes to your new branch as appropriate. Once the SOS code is fully functional, create a Pull Request (PR) on the original repository. 
- Person 1: Review the PR and merge it into your main repository's main branch if appropriate.

## More Resources
The University of Colorado Boulder's Earth Lab has some amazing open training tools that go much further than the basics presented here. Check this link out for much, much more: https://earthlab.colorado.edu/our-work/teaching-and-learning-earth-data-science/open-educational-resources. 