package chapter_two;

/**
 * Created by wengwei on 17-6-11.
 */

class Account{
    private double balance;
    public double getBalance(){
        return balance;
    }
    public void setBalance(double balance){
        this.balance = balance;
    }
    //public synchronized void addAmount(double amount){
    public void addAmount(double amount){
        double tmp = balance;
        try{
            Thread.sleep(10);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        tmp += amount;
        balance = tmp;
    }
//    public synchronized void subtractAmount(double amount){
    public void subtractAmount(double amount){
        double tmp = balance;
        try{
            Thread.sleep(10);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        tmp -= amount;
        balance = tmp;
    }
}
public class P1Bank implements Runnable{
    private  Account account;
    public P1Bank(Account account){
        this.account = account;
    }

    @Override
    public void run() {
        for(int i=0;i<100;++i){
            account.subtractAmount(1000);
        }
    }
}

class Company implements Runnable{
    private Account account;
    public Company(Account account){
        this.account = account;
    }

    @Override
    public void run() {
       for(int i=0;i<100;++i){
           account.addAmount(1000);
       }
    }
}

class Main{
    public static void main(String[] args){
        Account account = new Account();
        account.setBalance(1000);
        Company company = new Company(account);
        Thread companyThread = new Thread(company);
        P1Bank bank = new P1Bank(account);
        Thread bankThread = new Thread(bank);
        System.out.printf("Account:Initial Balance:%f\n",account.getBalance());
        companyThread.start();
        bankThread.start();
        try{
            companyThread.join();
            bankThread.join();
            System.out.printf("Account : Final Balance:%f\n",account.getBalance());
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
