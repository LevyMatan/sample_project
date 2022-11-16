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

    steps:
      - name: Print greeting
        run: echo "Hello workflow!"
      - name: Print goodbye
        run: echo "Bye Bye!"
```

## Events (Workflow Triggers)

Repository-related:

- **push:** pushing a commit
- **pull_request:** pull request action (opened, closed, ...)
- **create:** A branch or tag was created.
- **fork:** Repository was forked.
- **issues:** An issue was opened, deleted, ...
- **issue_comment:** Issue or pull request comment action.
- **watch:** Repository was starred.
- **discussion:** Discussion action (created, deleted, ...)
- Many more!

Others:

- **workflow_dispatch:** Manually trigger workflow.
- **repository_dispatch:** REST API request triggers workflow
- **schedule:** workflow is scheduled
- **workflow_call:** Can be called by other workflows.

For more info: search google for "github events"

Example:

```yml
name: Test Project

on: push
# later we can add attributes

jobs:
  basic:
    runs-on: ubuntu-latest

    steps:
        # The runner doesn't automatically have our code.
      - name: Get code
        uses: actions/checkout@v3
```
