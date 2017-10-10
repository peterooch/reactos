# How To Contribute
There are several ways to contribute to the development of ReactOS. The most often encountered problem is not knowing where to begin or what to do. If you are able to program or understand the technical information that is pertinent to this project, helping the development can be easy.

## Documentation

There are some important points if you'd like to help document ReactOS:

1.  Make sure the documentation doesn't exist yet (if it does, help improve it).
2.  Respect [clean room reverse engineering] practices.
3.  Add your knowledge to a place where the other developers can find it.

## Test ReactOS

### Localize bugs

By localizing bugs, developers can identify what causes the bug and what it affects. There are a variety of methods to [debug] ReactOS while testing it. After identifying a bug, check if it is already known about by searching [JIRA] and adding any additional information to the report. If you think that it is an unidentified bug, consider [filing a bug report].

### Fix bugs

Instead of looking for bugs, you can also try to fix a few that are already listed in JIRA. Fixing bugs requires a lot more skill than simply searching for them, and can be time consuming.

### Write tests

Tests are used to check the functionality and correctness of APIs on ReactOS compared to Windows implementations. There are also some unit tests that you could help ReactOS pass, which can be found [here][testman].

## Implement new things

Considering ReactOS is alpha quality software, there is a lot of [missing functionality] that Windows operating systems have. Before starting a project to implement something, find out if another person is working on the same thing. If you find that someone is already working on it, ask if any assistance is needed for what specifically is being worked on or a related project. Plenty of times a person will start to implement something and never finish before moving to something else. Make sure you stay committed to what you are going to implement, and do not be afraid to ask for assistance if you need help with something.

## Contribute

Your contribution can be of numerous forms. We currently accept two ways to contribute - Pull Requests and Patches.

### Pull Requests

Since our [migration to GitHub] we gladly accept [Pull Requests]. Pull requests let you tell others about changes you've pushed to a repository on GitHub. Once a pull request is opened, you can discuss and review the potential changes with collaborators and add follow-up commits before the changes are merged into the repository. Pull request is a prefered way to submit your work - it makes reviewing and merging your contribution much easier.

### Patches

A [patch] is a set of changes to existing source code. The changes in a patch can be merged into existing source code. This process is referred to as applying a patch (to source code). Which changes a patch contains and the way the patch is structured can have significant impact on the consequences that can happen from applying the patch. 

See [Submitting Patches] for details.

### Rules and Recomendations
Regardless of your way of contributing to ReactOS we have some rules and recomendations:

- Use your __full real name__ and __real email__. We don't accept anonymous contributions!
- Ensure your contribution is properly described. Include the relevant issue number if applicable.
- Put only related changes. It will make reviewing easier as the reviewer needs to recall less information about the existing source code that is changed.
- Search for similar pull requests/patches before submitting. It may be that a similar pull request or issue was opened previously. Comment and review on that one instead.
- Keep your contribution small and focused on the topic. It can be tempting to fix existing issues as you come across them while reading the source code. Resist the temptation and put in a note in the source code instead, or (even better) put the issue in the issue tracking system.
- Respect our Coding Style. See [Coding Style] and [Programming Guidelines] for details on how to write your code.
- Don't be afraid to ask questions. Ask our developers on JIRA or [IRC] channel.

## Finding a good project to start

Finding a good project to start with can be a challenge, because when starting out you are (usually) not aware of all the possibilities. To help you find a project, here are some ideas to try:

-   Find a test that fails, and try to make it succeed: <https://www.reactos.org/testman/>
-   Look around in JIRA, and if you have problems finding nice projects to start with, there is a label for this: <https://jira.reactos.org/issues/?jql=labels%20%3D%20starter-project>
-   Ask for help in [IRC]
-   Additionally, there are some tests that cause crashes/hangs, but these might be slightly harder: <https://jira.reactos.org/browse/ROSTESTS-125>

  [clean room reverse engineering]: https://en.wikipedia.org/wiki/Clean_room_design
  [debug]: https://reactos.org/wiki/Debugging
  [JIRA]: http://jira.reactos.org/
  [filing a bug report]: https://reactos.org/wiki/File_Bugs
  [testman]: http://www.reactos.org/testman/
  [migration to GitHub]: https://www.reactos.org/project-news/reactos-repository-migrated-github
  [humans are terrible at tracking large amount of information]: http://www.eurekalert.org/pub_releases/2005-03/aps-hmc030805.php
  [Pull requests]: https://help.github.com/articles/about-pull-requests/
  [tips for reviewing patches]: http://drupal.org/patch/review
  [missing functionality]: https://reactos.org/wiki/Missing_ReactOS_Functionality
  [patch]: https://git-scm.com/docs/git-format-patch
  [Submitting Patches]: https://reactos.org/wiki/Submitting_Patches
  [amend]: https://git-scm.com/book/en/v2/Git-Tools-Rewriting-History
  [Coding Style]: https://reactos.org/wiki/Coding_Style
  [#reactos]: https://www.reactos.org/irc
  [IRC]: https://reactos.org/wiki/Connect_to_the_ReactOS_IRC_Channels
  [Programming Guidelines]: https://reactos.org/wiki/Programming_Guidelines
