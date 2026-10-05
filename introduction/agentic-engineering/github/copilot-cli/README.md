# GitHub Copilot CLI 

GitHub Copilot CLI **bridges the gap between natural language and 
the command line**. Instead of digging through man pages, Stack Overflow, 
or documentation to remember obscure flags, we can interact with an AI 
agent right inside our terminal.

## Prompt Processing

The core concept behind Copilot CLI is **execution-focused AI**.

When we submit a prompt (e.g., "Find all .log files larger than 100MB 
and compress them"), Copilot CLI processes it using a **contextual loop**:

* **Context Gathering**: It inspects our current shell environment 
(detecting if we are running Bash, Zsh, or PowerShell), checks our 
working directory, analyzes file structures, and evaluates our recent 
Git history. We can explicitly point it to files using the `@` symbol 
(e.g., Summarize @README.md).

* **Intent Translation**: The underlying model translates our plain-English 
request into actionable shell commands, scripts, or multi-step action plans.

* **Safety Gate & User Approval**: It presents the proposed command or 
script along with a detailed plain-English breakdown of what each flag 
and pipe actually does.

* **Execution**: It never executes a command blindly. We must explicitly 
review and approve it:
    - **Allow**: Run the command immediately.
    - **Deny**: Reject the command and alter your prompt.
    - **Allow for session**: Trust this specific class of tools for the 
    duration of our session without getting prompted again.

## Setup

We can install Copilot CLI using `Node.js` 22 or later:

```bash
$ npm install -g @github/copilot
```

## Interaction Modes

Beyond the standard typing interface, we can fundamentally change how the 
CLI behaves on the fly using shortcuts:

* **Standard Mode**: To launch GitHub Copilot CLI in its default, 
interactive chat state, we simply navigate to our target project 
folder and run:

    ```bash
    $ copilot 
    ```

* **! Shortcut (Shell Mode)**: If we are inside an interactive Copilot 
session but quickly need to run a standard, manual terminal command 
without exiting, type `!` at the start of our line (e.g., `!git status`). 
It bypasses the AI completely and triggers a direct shell pass-through.

* **Programmatic Mode (-p)**: If we don't want the interactive UI at all,
especially useful for piping outputs, automation, or CI/CD pipelines, we 
can execute one-shot commands from your standard terminal prompt:

    ```bash
    $ copilot -p "Show me this week's Git commits and summarize them"
    ```

## Slash Commands

Once we launch the interactive interface by typing `copilot` in our terminal, 
we communicate via natural language and a suite of power-user slash commands.

### Core Utilities

* `/help`: Displays a menu of all available slash commands and active global 
    shortcuts. 

* `/clear`: Clears the current conversation thread to give us a fresh, clean 
    slate.

* `/model`: Allows us to manually switch between available AI models depending 
    on the complexity of your task. 


### Context & Space Management
Because terminal workflows can involve a massive amount of output, managing 
our context window (token limit) is vital.

* `/context`: Gives us a visual overview of how our current token budget is 
    being distributed.

* `/compact`: Manually shrinks and compresses older conversation history to 
    free up token space without wiping the session.

* `/usage`: Displays real-time statistics of our session, including API 
    requests used, lines of code edited, and token breakdowns.


### Mode Shifting & Code Analysis

* `/plan`: Forces Copilot to slow down and map out a structured, multi-step 
    implementation plan before writing any code or executing terminal blocks.

* `/diff`: Opens a visual review pane showing exactly what changes Copilot 
    has introduced to our local files before you commit to them.


- `/copy` copy the last response to the clipboard 
- `/share` share session to MD file or GitHub gist


## Custom Instructions (Priming Documents)

* **Agent instructions**: These are used by various AI agents.

    We can create one or more `AGENTS.md` files. These can be located in 
    the repository's root directory, in the current working directory, or 
    in any of the directories specified by a comma-separated list of paths 
    in the COPILOT_CUSTOM_INSTRUCTIONS_DIRS environment variable.

    Instructions in the AGENTS.md file in the root directory are treated 
    as primary instructions.

* **GitHub Copilot**: Repository-wide custom instructions which apply 
    to all requests made in the context of a repository.

    These are specified in a `copilot-instructions.md` file in 
    the `.github` directory at the root of the repository.

    We can also use **/init** to generate initial Copilot instructions 
    for a given repository.

The instructions in the file(s) are available for use by Copilot as soon 
as we save the file(s). Instructions are automatically added to requests 
that we submit to Copilot.

If we make changes to your custom instructions during a CLI session, our 
changes are available for use by Copilot the next time we submit a prompt 
in the current, or future, sessions.


## References

* Custom Instructions
    - [YouTube (Net Ninja): Copilot CLI Tutorial - Custom Instructions](https://youtu.be/oA1LDB9tdZU?si=HnVYRYWroRBwnH1k)

    - [GitHub Copilot Documentation: Adding custom instructions for GitHub Copilot CLI](https://docs.github.com/en/copilot/how-tos/copilot-cli/customize-copilot/add-custom-instructions)

*Egon Teiniker, 2020-2026, GPL v3.0* 
