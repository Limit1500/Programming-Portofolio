let newTask_input = document.querySelector(".input");
let sumbit_button = document.querySelector("button");
let unorderList = document.querySelector(".unorderList");
let delete_buttons = document.querySelectorAll(".delete_img");
let edit_buttons = document.querySelectorAll(".edit_img");

let target,
  rem = 0,
  tasks = 0;

function addTask() {
  if (tasks < 8 && newTask_input.value != "") {
    tasks++;
    newTask_input.placeholder = "New task";
    let li = document.createElement("li");
    unorderList.append(li);
    li.append(newTask_input.value);

    let edit_img = document.createElement("img");
    li.append(edit_img);
    edit_img.className = "edit_img";
    edit_img.src = "images/editButton.png";

    let delete_img = document.createElement("img");
    li.append(delete_img);
    delete_img.className = "delete_img";
    delete_img.src = "images/deleteButton.png";

    newTask_input.value = "";

    if (rem == 1) target.parentNode.remove();
    rem = 0;

    acceptMoves();
  }
}

function acceptMoves() {
  unorderList.addEventListener("click", (event) => {
    target = event.target;
    if (target.className == "delete_img") {
      target.parentNode.remove();
      tasks--;
    } else if (target.className == "edit_img") {
      newTask_input.placeholder = "Edit here";
      let newText = document.createTextNode("Editing");
      rem = 1;
    }
  });
}

sumbit_button.addEventListener("click", addTask);
