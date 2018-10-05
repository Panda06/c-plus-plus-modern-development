#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const std::string& event) const {
    return true;
}

bool DateComparisonNode::Evaluate(const Date& _date,
                                  const std::string& _event) const {
    switch (cmp) {
        case Comparison::Less:
            return _date < date;
        case Comparison::LessOrEqual:
            return _date <= date;
        case Comparison::Greater:
            return _date > date;
        case Comparison::GreaterOrEqual:
            return _date >= date;
        case Comparison::Equal:
            return _date == date;
        case Comparison::NotEqual:
            return _date != date;
        default:
            throw std::logic_error("Invalid Comparison value");
    }
    return false;
}

bool EventComparisonNode::Evaluate(const Date& date,
                                   const std::string& _event) const {
    switch (cmp) {
        case Comparison::Less:
            return _event < event;
        case Comparison::LessOrEqual:
            return _event <= event;
        case Comparison::Greater:
            return _event > event;
        case Comparison::GreaterOrEqual:
            return _event >= event;
        case Comparison::Equal:
            return _event == event;
        case Comparison::NotEqual:
            return _event != event;
        default:
            throw std::logic_error("Invalid Comparison value");
}
    return false;
}
bool LogicalOperationNode::Evaluate(const Date& date,
                                    const std::string& _event) const {
    switch (operation) {
        case LogicalOperation::And:
            return left->Evaluate(date, _event) && right->Evaluate(date, _event);
        case LogicalOperation::Or:
            return left->Evaluate(date, _event) || right->Evaluate(date, _event);
        default:
            throw std::logic_error("Invalid LogicalOperation value");
     }
     return false;
}
