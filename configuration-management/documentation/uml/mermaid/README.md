# Mermaid

Mermaid lets create (UML) diagrams and visualizations using text and code.

It is a JavaScript based diagramming and charting tool that renders 
Markdown-inspired text definitions to create and modify diagrams dynamically.


## Flowchart 

A Flowchart is a type of diagram that represents a workflow or process. It is different 
from the UML Activity Diagram in that it does not have a formal specification.

_Example:_
```mermaid
```

## UML State Machine Diagram 


_Example:_ Light Bulb State Machine Diagram

```mermaid
stateDiagram-v2 
    [*] --> OFF
    OFF --> ON: turn_on()/current_on()
    ON --> OFF: turn_off()/current_off()
    ON --> [*]: burn_out()/current_off()
```


## Setup 

To use Mermaid in VS Code, install the following extension:

![Mermaid Extension](figures/VSCodeExtension-MermaidEditor.png)]



## References

* [Mermaid User Guide](https://mermaid.js.org/intro/getting-started.html)

* [Mermaid Live Editor](https://mermaid.live/edit)

* [VS Code Extension: Mermaid Editor](https://marketplace.visualstudio.com/items?itemName=tomoyukim.vscode-mermaid-editor)


*Egon Teiniker, 2020-2025, GPL v3.0* 