package jpql;


import jakarta.persistence.*;

import java.util.List;

public class JpqlMain {
	public static void main(String[] args) {
		EntityManagerFactory emf = Persistence.createEntityManagerFactory("hello");
		EntityManager em = emf.createEntityManager();
		//code
		EntityTransaction tx = em.getTransaction();
		tx.begin();
		try {
			Team team = new Team();
			team.setName("team1");
			em.persist(team);

			Member member = new Member();
			member.setAge(10);
			member.setMemberType(MemberType.USER);
			member.setUsername("member1");
			member.changeTeam(team);

			em.persist(member);

			String query1 = "select " +
								"case when m.age <= 10 then '학생요금' " +
								"	  when m.age >= 60 then '경로요금' " +
								"     else '일반요금' " +
								"end " +
					"from Member m";
			List<Member> result1 = em.createQuery(query1, Member.class)
					.getResultList();

			String query2 = "select coalesce(m.username, '이름 없는 회원') from Member m";
			List<Member> result2 = em.createQuery(query2, Member.class)
					.getResultList();

			tx.commit();
		} catch (Exception e) {
			tx.rollback();
		} finally {
			em.close();
		}

		emf.close();
	}
}
