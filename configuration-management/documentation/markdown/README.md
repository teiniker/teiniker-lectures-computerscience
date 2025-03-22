# Markdown Files

Markdown (MD) is a **lightweight markup language** designed for easy-to-read 
and easy-to-write plain text formatting. It's widely used to create formatted 
text in documents, websites, blogs, README files, documentation, and chat 
platforms (like GitHub, Reddit, and Stack Overflow).

Markdown was originally created by **John Gruber** in 2004 with the intention 
of making content easy to read in its plain-text form, while still allowing 
it to be easily converted to structurally valid HTML.

Markdown (often abbreviated as "MD") is a lightweight markup language designed for easy-to-read and easy-to-write plain text formatting. It's widely used to create formatted text in documents, websites, blogs, README files, documentation, and chat platforms (like GitHub, Reddit, and Stack Overflow).

Markdown was originally created by **John Gruber** in 2004 with the intention of making content easy to read in its plain-text form, while still allowing it to be easily converted to structurally valid HTML.


## Basic Syntax Examples

### Headings:
Use `#` symbols for headings:
```markdown
# Heading Level 1
## Heading Level 2
### Heading Level 3
```

### Emphasis (bold and italics):
```markdown
*Italic text*
**Bold text**
***Bold and italic text***
```

### Lists:

- **Unordered List:**
```markdown
- Item 1
- Item 2
  - Nested item
```

- **Ordered List:**
```markdown
1. First item
2. Second item
3. Third item
```

### Links:
```markdown
[Link Text](https://example.com)
```

### Images:
```markdown
![Alt Text](image-url.jpg)
```

### Inline Code:
Wrap inline code with backticks (`` ` ``):
```markdown
Use the `print()` function.
```

### Code Blocks:
Wrap multi-line code with triple backticks (` ``` `):
````markdown
```python
def greet(name):
    print(f"Hello, {name}")
```
````

### Blockquotes:
```markdown
> This is a quoted text.
```

### Tables:
```markdown
| Column A | Column B |
| -------- | -------- |
| Value A  | Value B  |
```


## Using Markdown in Projects 

Markdown (MD) serves several important roles within software projects, 
primarily due to its simplicity, readability, and **integration with 
common developer tools**.


### **README files**
Every software repository benefits from a clear README file, usually 
named `README.md`. It is often the first point of contact for users 
and developers.

**Example content:**
- Project Overview
- Installation & Setup
- Usage examples
- Contribution guidelines
- Licensing


### **Documentation**
Markdown makes documentation easy to write, update, and maintain.

Typical documentation includes:
- API documentation
- User manuals
- Developer guides
- Technical specifications


### **Issue Tracking and Pull Requests**
Many version control platforms, such as GitHub and GitLab, use Markdown 
for writing clear, structured issues and pull requests.

Useful for:
- Writing issue reports (bugs, features)
- Pull Request (PR) descriptions
- Task checklists
- Code review notes


### **Changelogs**
Markdown is ideal for writing clear changelogs (usually named 
`CHANGELOG.md`) that track software releases, updates, and fixes.

Typical structure:
```markdown
## [v1.2.0] - YYYY-MM-DD
### Added
- New feature A

### Fixed
- Issue #123: Resolved crash when input is empty
```

### **Code Comments and Tutorials**
Markdown can be embedded in codebases to document important functions, 
classes, or processes clearly.

Example use cases:
- Inline tutorials or explanatory notes
- Step-by-step walkthroughs or guides in the repository


### **Wiki Pages**
Tools such as GitHub Wikis and GitLab Wikis natively support Markdown, 
allowing teams to maintain collaborative, easily editable documentation.

Common use cases:
- Project standards and guidelines
- Team workflows
- Onboarding instructions

## References

* [Markdown Cheatsheet](https://github.com/adam-p/markdown-here/wiki/markdown-cheatsheet)
* [Quickstart for writing on GitHub](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/quickstart-for-writing-on-github)

*Egon Teiniker, 2020-2025, GPL v3.0*         
