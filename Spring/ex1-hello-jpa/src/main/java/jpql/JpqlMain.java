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

			// 컬렉션에서는 탐색이 불가능하기 때문에 명시적으로 조인을 해주어야 탐색이 가능
			String query1 = "select t.members from Team t";
			List<Member> members1 = em.createQuery(query1, Member.class).getResultList();

			String query2 = "select m.username from Team t join t.members m";
			List<Member> members2 = em.createQuery(query2, Member.class).getResultList();
			tx.commit();
		} catch (Exception e) {
			tx.rollback();
		} finally {
			em.close();
		}

		emf.close();
	}
}
