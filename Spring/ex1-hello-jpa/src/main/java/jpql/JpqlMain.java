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
			member.setUsername("member1");
			member.changeTeam(team);

			em.persist(member);

			String query1 = "select m from Member m inner join m.team t";
			List<Member> result1 = em.createQuery(query1, Member.class)
					.getResultList();

			String query2 = "select m from Member m left join m.team t";
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
