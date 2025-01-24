let tasks = [];

function addTask() {
  const taskInput = document.getElementById("taskInput");
  const timeInput = document.getElementById("timeInput");
  const task = {
    name: taskInput.value,
    time: timeInput.value,
    completed: false
  };
  tasks.push(task);
  taskInput.value = "";
  timeInput.value = "";
  displayTasks();
}

function deleteTask(index) {
  tasks.splice(index, 1);
  displayTasks();
}

function toggleTaskCompletion(index) {
  tasks[index].completed = !tasks[index].completed;
  displayTasks();
}

function displayTasks() {
  const unfinishedTasksList = document.getElementById("unfinishedTasks");
  const finishedTasksList = document.getElementById("finishedTasks");

  unfinishedTasksList.innerHTML = "";
  finishedTasksList.innerHTML = "";

  tasks.forEach((task, index) => {
    const li = document.createElement("li");
    li.textContent = `${task.name} (${task.time})`;
    li.className = task.completed ? "completed" : "";
    li.addEventListener("click", () => toggleTaskCompletion(index));

    const deleteBtn = document.createElement("button");
    deleteBtn.textContent = "Delete";
    deleteBtn.addEventListener("click", (e) => {
      e.stopPropagation();
      deleteTask(index);
    });

    li.appendChild(deleteBtn);

    if (task.completed) {
      finishedTasksList.appendChild(li);
    } else {
      unfinishedTasksList.appendChild(li);
    }
  });
}
