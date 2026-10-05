# Agentic Engineering

## Evolution of Generative AI 

Generative AI did not arrive in software development as a finished coding 
agent. It moved through several stages, each one handing the model more 
context about our code and more control over our tools.

### Stage 1: Chatbot

The model lives in a **separate window**, completely disconnected from our 
editor and our project. We ask a question or paste a snippet, read the 
answer, and copy the result back into our own files by hand. The model has 
no access to our codebase; it only knows what we typed into the chat.

*Example:* Asking ChatGPT (2022) or Claude.ai "write a function that parses 
a CSV file in Python", then copy-pasting the generated function into our 
own editor.

### Stage 2: IDE Autocomplete

The model moves **into the editor**, but stays passive. It observes the 
current file (and sometimes a few open tabs) and silently suggests the 
next few lines at the cursor. There is no conversation, just an inline 
suggestion we accept with `Tab` or dismiss by continuing to type.

*Example:* GitHub Copilot's ghost-text completions, or Tabnine, finishing 
a `for` loop or a function signature as we type it.

### Stage 3: Inline Chat

The editor gains a **chat panel** that can see our open files and, on 
request, parts of our project. We can ask it to explain a function, write 
a test, or refactor a block, and it proposes a diff. We still drive every 
turn: we ask, review, and click "Apply" (or reject) for each change 
individually.

*Example:* GitHub Copilot Chat or Cursor's Chat/Composer panel, where we 
ask "add error handling to this function" and manually approve the 
suggested diff.

### Stage 4: Coding Agents

The model is wrapped in a **harness that gives it tools**: read files, 
edit files, run shell commands, run tests, search the repository. Instead 
of one suggestion per turn, the model runs a loop: it reads what it needs, 
makes a change, runs the tests, reads the failure, and tries again, 
largely on its own, across many files, until the task is done.

*Example:* Claude Code, given the task "add a `stack_top` bounds check and 
make the tests pass," reads `stack.c` and `test.c`, edits the source, 
runs `make test`, and iterates on the result without us reviewing every 
intermediate step.


## Important Terms

The following section defines the most important terms necessary for 
understanding Coding Agents.

### Tokens
Everything is measured in tokens: **chunks of text** roughly ¾ of a word each 
in English (code tends to tokenize less efficiently, so it eats more tokens 
per line than you'd guess). 


### Prompt 
The prompt is **the instruction we write for the current turn**: the 
question or task we type, on its own, before the harness assembles 
anything around it.


### Context

The context is the **total text actually fed into the model** for one 
forward pass. The harness builds it by concatenating the system prompt, 
tool schemas, the past conversation history, retrieved documents, and 
our current prompt into a single token sequence. The prompt is only one 
ingredient in the context; everything else is added around it before it 
reaches the model.

* **Context Window:** This is the absolute limit of data the model can 
    process at one time. It is measured in tokens.

* **Context Window Exhaustion**: If a session goes on for weeks and the 
    sheer volume of text exceeds the model's context window (its token 
    limit), the application will begin "summarizing" older parts of the 
    session or dropping the oldest messages entirely to make room for 
    new ones.

* **Context Rot**: Model quality degrades as the context fills up, even 
    before we hit the hard token limit. Instructions and details buried 
    early in a long session get less attention than recent turns, so the 
    model can start ignoring an earlier constraint or forgetting a detail we 
    mentioned, 
    simply because too much unrelated text has piled up in between. This is 
    why compacting, or starting a fresh session for a new sub-task, often 
    gives sharper results than pushing one long session to its limit.


### Session
A session (often called a thread or a conversation) is the organizational 
boundary managed by the application layer to keep a single, continuous 
conversation separate from all others.

We can think of a session as a dedicated folder or container. Every 
time we start a "New Chat," the application generates a unique 
Session ID in its database.
    
This container stores:
- Every prompt we type
- Every response the AI generates
- The specific system instructions and model settings used for that 
    specific chat

When we switch between different chats, we are simply jumping between 
different session IDs stored in the application's database.


## Prompt Engineering

Because LLMs are stateless text-prediction engines, they rely entirely 
on the patterns and constraints provided in the context. 
**Prompt engineering** is the practice of structuring the input to 
narrow down the model's vast probability map into the exact type of 
response we want.

Here is how different prompt engineering techniques directly alter 
the quality of the output:

* **Reducing "Hallucinations" via Constraints:** If we tell a model to 
*"Answer only using the provided text, and say 'I don't know' if it isn't there,"* 
we drastically reduce its tendency to make things up.

* **Priming the Pattern (Few-Shot Prompting):** Giving the model 2 or 3 
examples of the exact input/output format you want establishes a pattern. 
The model's core mechanism is pattern completion, so its quality sky-rockets 
when a pattern is clearly established.

* **Activating Neural Pathways (Role Prompting):** Telling a model to 
*"Act as a senior software architect"* forces it to heavily weigh words, 
concepts, and structures associated with expert coding in its training data, 
filtering out generic or beginner-level responses.

* **Enabling Better Reasoning (Chain-of-Thought):** Asking a model to 
*"Think step-by-step before answering"* forces it to generate its intermediate 
logic out loud. Because it predicts text sequentially, generating the correct 
logic steps *first* drastically increases the mathematical probability that 
the final answer will be correct.


## Context Engineering

Prompt engineering optimizes **what we type** for a single turn. 
**Context engineering** is the broader discipline of curating everything 
else the harness assembles around that prompt: which files, tool 
outputs, past messages, and external documents actually get fed into the 
model's context window before it sees our request at all.

The distinction matters because a coding agent's context is not written 
by a person, it is assembled automatically on every turn out of 
conversation history, file contents, search results, and tool results. A 
perfectly worded prompt still produces a bad answer if the one relevant 
function was never read into context, or if it is buried under logs and 
files that have nothing to do with the task.

* **Prompt Engineering vs. Context Engineering:** Prompt engineering asks 
*"How do I phrase this instruction?"* Context engineering asks *"What 
does the model actually need to see to carry out this instruction 
correctly?"* The first shapes the request; the second shapes the 
evidence the model reasons over.

* **Selective Retrieval:** Rather than loading an entire repository into 
the context window, a well-engineered agent reads only the files, 
functions, or documentation sections relevant to the current task. This 
leaves more of the context window free for actual reasoning instead of 
irrelevant code.

* **Fighting Context Rot:** Because model quality degrades as unrelated 
text piles up (see **Context Rot** above), context engineering also 
means actively removing what is no longer needed: summarizing finished 
sub-tasks, dropping stale tool output, or starting a fresh session once 
a task is truly done, rather than letting every prior turn linger in the 
window.

* **Sub-Agent Isolation:** Delegating a sprawling, exploratory sub-task 
(for example, "search the codebase for every place a deprecated API is 
used") to a separate agent keeps its noisy intermediate steps, failed 
attempts, and file dumps out of the main session's context. Only the 
final, distilled result is returned to the calling agent.

* **Structured Tool Design:** How a tool's output is formatted is itself 
context engineering. A tool that returns a concise, structured summary 
(e.g. "3 files match, see list") consumes far fewer tokens, and is easier 
for the model to act on, than one that dumps raw, unfiltered output back 
into the conversation.

*Example:* Claude Code deciding to spawn a sub-agent for a broad 
repository search, then only pulling its short summary back into the 
main session, is context engineering in action, it protects the primary 
context window from being consumed by the search's raw intermediate 
output.


## Working with Lecture Repositories

The repositories used in this class consist of **Markdown files**, 
**demo examples**, **exercises**, and **model solutions**.

To support **self-directed learning** with GitHub Copilot, the following activities 
are recommended for each content type:

* **Markdown Files**: MD files explain key concepts and programming techniques 
    to provide foundational knowledge.
    
    - Read the MD files and follow the references.
    
    - Use *Copilot Chat* to ask questions about the concepts and explanations. 
        Discuss the respective answers.

* **Demo Examples**: These are working examples with test cases that demonstrate 
    implementation variants of a specific concept.

    - Read the source code and test cases of the example to understand 
        the concrete implementation of a concept.

    - Use *Copilot Chat* to ask questions about the implementation or 
        possible implementation variants.
    
    - Use *Inline Chat* to refactor parts of the example (verify success 
        by running the tests).

* **Exercises**: Practice examples that include test cases and require you to add 
    specific implementation artifacts to make the tests pass. Each exercise focuses 
    on a particular concept.
    
    - Read the `TODO.txt` file and implement the missing source code artifacts.
        Verify your implementation step by step by running the existing test cases.

    - **Focus on Implementation**: To learn and practice the fundamentals of C/C++
        programming, disable *Code Suggestions* and work without *Inline Chat*.
        Ask in *Copilot Chat* if you need specific programming constructs or 
        libraries. Compare your solution with the Model Solution.

    - **Focus on Design and Architecture**: To efficiently implement different 
        design and architectural patterns, use *Code Suggestions* and 
        *Inline Chat*.
        You should be able to understand and evaluate the generated code. 
        
    - **Don't copy the `TODO.txt` file into a Chatbot to generate the solution**:
        It's faster to simply review the Model Solution instead. However, be 
        aware that the learning outcome is minimal if you only skim the finished 
        solution.

* **Model Solutions**: They demonstrate one (of several possible) approaches 
    to solve a particular exercise. 

    - Use *Copilot Chat* to ask questions about the implementation or 
        possible implementation variants.

    - Use *Copilot Chat* to analyze the differences between your solution and 
        the Model Solution and discuss the different approaches.

This approach works particularly well for working through many small examples 
and exercises. For larger tasks affecting many source files simultaneously, 
we will use **Coding Agents**.


## References

* [YouTube (Matt Pocock): Most devs don't understand how LLM tokens work](https://youtu.be/nKSk_TiR8YA?si=0w2MMky8XPKCD4k5)
* [YouTube (Andrej Karpathy): Deep Dive into LLMs like ChatGPT](https://youtu.be/7xTGNNLPyMI?si=X8CJSDOogrZp7KyO)

* [Exploring Generative AI](https://martinfowler.com/articles/exploring-gen-ai.html)

*Egon Teiniker, 2020-2026, GPL v3.0*  