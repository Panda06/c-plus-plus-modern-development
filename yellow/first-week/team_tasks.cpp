#include <vector>
TaskStatus NextStatus(TaskStatus& status) {
    return static_cast<TaskStatus>(static_cast<int>(status) + 1);
}
void DelZero(TasksInfo& tasks) {
    vector<TaskStatus> v;
    for (const auto& item : tasks) {
        if (item.second == 0) {
            v.push_back(item.first);
        }
    }
    for (const TaskStatus& status : v) {
        tasks.erase(status);
    }
}
class TeamTasks {
public:
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
      return tasks.at(person);
  }

  void AddNewTask(const string& person) {
      ++tasks[person][TaskStatus::NEW];
  }

  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count) {
          TasksInfo updated_tasks, untouched_tasks;

          for (TaskStatus s = TaskStatus::NEW;
               s != TaskStatus::DONE && task_count > 0;
               s = NextStatus(s)) {
              updated_tasks[NextStatus(s)] = min(task_count, tasks[person][s]);
              task_count -= updated_tasks[NextStatus(s)];
          }

          for (TaskStatus s = TaskStatus::NEW;
               s != TaskStatus::DONE;
               s = NextStatus(s)) {
              untouched_tasks[s] = tasks[person][s] - updated_tasks[NextStatus(s)];
              tasks[person][s] += updated_tasks[s] - updated_tasks[NextStatus(s)];
          }
          tasks[person][TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];
          DelZero(updated_tasks);
          DelZero(untouched_tasks);
          return {updated_tasks, untouched_tasks};
      }
private:
    std::map<std::string, TasksInfo> tasks;
};
