class INotifier {
public:
    virtual void Notify(const string& message) = 0;
};

class SmsNotifier : public INotifier {
public:
    SmsNotifier(const string& _phone) : phone(_phone) {}
    void Notify(const string& message) override {
        SendSms(phone, message);
    }
private:
    string phone;
};

class EmailNotifier : public INotifier {
public:
    EmailNotifier(const string& _email) : email(_email) {}
    void Notify(const string& message) override {
        SendEmail(email, message);
    }
private:
    string email;
};
