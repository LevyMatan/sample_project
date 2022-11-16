# GitHub Actions

One must have a github repository.  
Basic building blocks for github-workflow:

- **Workflows**  
Workflows are attached to a GitHub repository.  
Contain one or more **Jobs**.  
Triggered upon **Events**.  

- **Jobs**  
Define a **Runner** (executation environment)  
Contain one or more **Steps**.  
Run in parallel (default) or sequential.  
Can be conditional.  

- **Steps**  
Execute a **shell script** or an **Action**.  
Can use custom or third-party actions.  
Steps are executed in order.  
Can be conditional.  

## First Workflow

```yml
name: Basic Workflow

# Allow the workflow to be triggered manually.
on: workflow_dispatch 

jobs:
    basic:
        # As mentioned, a job runs on a Runner
        # Hence we now have to define that Runner
        # For more info search for "github runners"
        runs-on: ubuntu-latest
```
