# GitHub Copilot 

GitHub Copilot is an AI-powered coding assistant developed by GitHub 
in collaboration with OpenAI, it uses large language models (LLMs) 
to suggest code, functions, and documentation in real-time within 
our Integrated Development Environment (IDE).

Core capabilities of GitHub Copilot:

* **Code Suggestions**: As we type, Copilot predicts the next 
    lines of code based on our current file, open tabs, and even 
    comments.  

	We can write a comment like 
    `// function to calculate distance between two GPS coordinates` 
    and Copilot will generate the implementation.

* **Copilot Chat**: A conversational sidebar that allows us to ask 
    questions like `"How does this function work?"` or 
    `"Refactor this to use async/await."`.  

* **Inline Chat**: A real-time conversational interface within our 
	code editor that allows us to ask GitHub Copilot questions and 
	receive contextual suggestions without leaving your editor window. 
	We can use it to explain code, generate snippets, refactor 
	existing code, or ask for help debugging. 
	
	Simply we highlight code or position our cursor and start a 
	chat session to get immediate assistance tailored to our 
	current work.

* **Agentic Workflows**: In its latest 2026 updates, Copilot can 
    act as an "AI Agent," autonomously planning multi-step tasks, 
    running tests, and opening Pull Requests.


## Code Suggestions

* [Getting code suggestions in your IDE with GitHub Copilot](https://docs.github.com/en/copilot/how-tos/get-code-suggestions/get-ide-code-suggestions)
	- Getting code suggestions:
		- Start typing code... `[Tab]`
		- Describe somethin you want within a comment... `[Tab]` 

	- Showing alternative suggestions: 
		- Next: `[Alt]+ ]` 
		- Previous: `[Alt]+ [`
		
		To accept a suggestion, click `[Accept]` in the Copilot command palette, or press `[Tab]`.

	- Accepting partial suggestions: ´[Ctrl] + [→]´


## Copilot Chat  

* [Getting started with prompts for GitHub Copilot Chat](https://docs.github.com/en/copilot/how-tos/chat-with-copilot/get-started-with-chat)

	You can ask Copilot Chat specific questions about your project or general software questions. You can also ask Copilot Chat to write code, fix errors, write tests, and document code.

	- **Ask general software questions**: You can ask Copilot Chat general software questions. 
	
		_Example_: tell me about nodejs web server frameworks

	- **Ask questions about your project**: You can ask Copilot Chat questions about your project.

		_Example_: what sorting algorithm does this function use

		To give Copilot the correct context, try some of these strategies:
		- Highlight relevant lines of code.
		- Use chat variables like `#selection`, `#file`, `#editor`, `#codebase`, or `#git`.
		- Use the `@workspace` chat participant.

	- **Write code**: You can ask Copilot to write code for you. 
	
		_Example_: write a function to sum all numbers in a list

		When Copilot returns a code block, the response includes options to copy the code, 
		or to insert the code at your cursor, into a new file, or into the terminal.


## Prompt Engineering 

* [Prompt engineering for GitHub Copilot Chat](https://docs.github.com/en/copilot/concepts/prompting/prompt-engineering)

A prompt is a request that we make to GitHub Copilot. 
For example, a question that we ask Copilot Chat, or a code snippet that we ask 
Copilot to complete. 

In addition to our prompt, Copilot uses additional context, like the code in our 
current file and the chat history, to generate a response.

* **Start general, then get specific**:
	- First give Copilot a broad description of the goal or scenario. Then list 
		any specific requirements.

* **Give examples**:
	- Use examples to help Copilot understand what you want. You can provide 
		example input data, example outputs, and example implementations.
	- Unit tests can also serve as examples. Before writing your function, 
		you can use Copilot to write unit tests for the function. Then, you 
		can ask Copilot to write a function described by those unit tests.

* **Break complex tasks into simpler tasks**:
	- If you want Copilot to complete a complex or large task, break the task 
		into multiple simple, small tasks.

* **Avoid ambiguity**:
	- Avoid ambiguous terms. Instead, be specific.

* **Indicate relevant code**: 
	- Open any relevant files and close irrelevant files. 
		Copilot will use the open files to understand your request.
	- Highlight the code that you want Copilot to reference.
	- Use keywords to manually supply context to Copilot Chat. 
		For example, you can add the `@workspace` chat participant in VS Code.

* **Experiment and iterate**:
	- If you don’t get the result that you want, iterate on your prompt 
		and try again.
	- If you are using Copilot Chat, you can reference the previous response 
		in your next request. Or, you can delete the previous response and 
		start over.

* **Keep history relevant**:
	- Copilot Chat uses the chat history to get context about your request.
		- Use threads to start a new conversation for a new task
		- Delete requests that are no longer relevant or that didn’t give you the desired result

* **Follow good coding practices**: 
	- Make sure that your existing code follows best practices and is easy to read.
		- Use a consistent code style and patterns
		- Use descriptive names for variables and functions
		- Comment your code
		- Structure your code into modular, scoped components
		- Include unit tests 


## References 

* [Get to know GitHub Copilot in VS Code and be productive IMMEDIATELY](https://youtu.be/jXp5D5ZnxGM?si=jJsmeyDQFjkbAwR_):

* [Best practices for using GitHub Copilot](https://docs.github.com/en/copilot/get-started/best-practices)


*Egon Teiniker, 2020-2026, GPL v3.0*