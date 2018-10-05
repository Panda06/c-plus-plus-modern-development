#pragma once

#include "date.h"
#include <memory>
#include <string>
#include <exception>

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation {
    And,
	Or
};

class Node {
public:
    virtual bool Evaluate(const Date& date, const std::string& event) const = 0;

};

class EmptyNode : public Node {
public:
    bool Evaluate(const Date& date, const std::string& event) const override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison c, const Date& d) : cmp(c), date(d) {}
    bool Evaluate(const Date& date, const std::string& event) const override;
private:
    Comparison cmp;
    Date date;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison c, const std::string& _event) :
                        cmp(c), event(_event) {}
    bool Evaluate(const Date& date, const std::string& event) const override;
private:
    Comparison cmp;
    std::string event;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(LogicalOperation op, std::shared_ptr<Node> lhs,
                         std::shared_ptr<Node> rhs) :
                         operation(op), left(lhs), right(rhs) {}
    bool Evaluate(const Date& date, const std::string& event) const override;
private:
    LogicalOperation operation;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
};
