package hellojpa;

import java.math.BigDecimal;
import java.util.Date;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.EnumType;
import jakarta.persistence.Enumerated;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.Lob;
import jakarta.persistence.SequenceGenerator;
import jakarta.persistence.Temporal;
import jakarta.persistence.TemporalType;
import jakarta.persistence.Transient;

@Entity
@SequenceGenerator(name = "member_seq_generator",
sequenceName = "member_seq",
initialValue = 1, allocationSize = 30)

public class Member {
	/**
	 * GenerationType.IDENTITY: MySQL, PostgreSQL, SQL Server...
	 * 기본 키 생성을 데이터베이스에 위임
	 * GenerationType.SEQUENCE: Oracle, ...
	 * 데이터베이스 시퀀스 오브젝트 사용
	 * GenerationType.TABLE:
	 *
	 * GenerationType.AUTO:
	 */
	@Id @GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "member_seq_generator")
	private Long id;
	@Column(name = "name", insertable = true, updatable = false, nullable = false)
	private String username;
	private BigDecimal age;
	@Enumerated(EnumType.STRING)// 필수 -> original 하면 enum추가됐을때 문제 생김
	private RoleType roleType;
	@Temporal(TemporalType.TIMESTAMP)
	private Date createdDate;
	@Temporal(TemporalType.TIMESTAMP)//LocalDateTime 사용하면 생략가능
	private Date lastModifiedDate;
	@Lob// 지정할 수 있는 속성이 없다.
	private String description;

	@Transient// 맵핑안됨
	private int temp;

	public Member() {}
	public Member(Long id, String name) {
		this.id = id;
		this.username = name;
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public BigDecimal getAge() {
		return age;
	}

	public void setAge(BigDecimal age) {
		this.age = age;
	}

	public RoleType getRoleType() {
		return roleType;
	}

	public void setRoleType(RoleType roleType) {
		this.roleType = roleType;
	}

	public Date getCreatedDate() {
		return createdDate;
	}

	public void setCreatedDate(Date createdDate) {
		this.createdDate = createdDate;
	}

	public Date getLastModifiedDate() {
		return lastModifiedDate;
	}

	public void setLastModifiedDate(Date lastModifiedDate) {
		this.lastModifiedDate = lastModifiedDate;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public int getTemp() {
		return temp;
	}

	public void setTemp(int temp) {
		this.temp = temp;
	}
}
