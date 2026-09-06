# Write your MySQL query statement below
select contest_id,round(Count(r.user_id)*100/(select count(*) from Users),2) as percentage from Users u join Register r on u.user_id = r.user_id group by contest_id order by percentage DESC,contest_id

