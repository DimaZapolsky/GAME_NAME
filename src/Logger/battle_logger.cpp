//
// Created by Dima Zapolsky on 2019/05/11.
//

#include "battle_logger.h"

void Battle_logger::battleHasEnded() {
    this->logs.clear();
}

void Battle_logger::addLog(std::shared_ptr<IBattle_log> const &single_log) {
    this->logs.push_back(single_log);
}

std::vector<std::shared_ptr<IBattle_log>> Battle_logger::getLogs() {
    return this->logs;
}

std::string Battle_logger::getStringLogs() {
    std::string log_result = "";
    for (auto const &current_log : this->getLogs()) {
        log_result += current_log->string_repr() + "\n";
    }
    return log_result;
}